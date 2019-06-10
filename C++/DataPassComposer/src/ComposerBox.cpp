#include "ComposerBox.h"
#include "DataPassComposer.h"

namespace DataPassComposer
{
	ComposerBox::ComposerBox()
	{
		Fields.clear();
		Directs.clear();
	}

	ComposerBox::~ComposerBox()
	{
		Fields.clear();
		Directs.clear();
	}

	void ComposerBox::AddBox(box_t box_id)
	{
		this_box_id = box_id;
	}

	/*private*/ void ComposerBox::SetField(field_t field_id, std::vector<uint8_t> vec)
	{
		Fields[field_id] = vec;
	}

	/*private*/ std::map<field_t, std::vector<uint8_t>>* ComposerBox::GetDirects()
	{
		return &Directs;
	}

	std::vector<uint8_t> ComposerBox::GetBinary(field_t field_id)
	{
		try
		{
			return Fields.at(field_id);
		}
		catch (std::out_of_range)
		{
			return std::vector<uint8_t>();
		}
		return std::vector<uint8_t>();
	}

	int ComposerBox::GetInt(field_t field_id)
	{
		std::vector<uint8_t> vec = ComposerBox::GetBinary(field_id);
		int val = 0;
		std::size_t size = vec.size();
		for (int i = 0; i < size; i++)
			val = (val << 8) | vec[i];
		return val;
	}

	bool ComposerBox::Direct(field_t field_id, std::vector<uint8_t> data)
	{
		size_t size = data.size() + BoxBytes + FieldBytes + 2;
		if (size >= 0xFFFF)
			return false;

		uint16_t cmd_size = size;
		std::vector<uint8_t> cmd;

		cmd.push_back((uint8_t)(cmd_size >> 8));//length
		cmd.push_back((uint8_t)cmd_size);

		uint8_t* p = (uint8_t*)&this_box_id;//box_id
		for (int i = BoxBytes - 1; i >= 0; i--)
			cmd.push_back(p[i]);

		p = (uint8_t*)&field_id;//field_id
		for (int i = FieldBytes - 1; i >= 0; i--)
			cmd.push_back(p[i]);


		cmd.insert(cmd.end(), data.begin(), data.end());//data

		Directs[field_id] = cmd;
		Composer.IndexBox(this_box_id);
		return true;
	}

	void ComposerBox::ClearDirects()
	{
		Directs.clear();
	}
}