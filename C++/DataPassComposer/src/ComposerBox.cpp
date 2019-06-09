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
	}

	void ComposerBox::AddBox(box_t index)
	{
		MyIndex = index;
	}

	/*private*/ void ComposerBox::SetField(field_t index, std::vector<uint8_t> vec)
	{
		Fields[index] = vec;
	}

	/*private*/ std::map<field_t, std::vector<uint8_t>>* ComposerBox::GetDirects()
	{
		return &Directs;
	}

	std::vector<uint8_t> ComposerBox::GetVector(field_t index)
	{
		try
		{
			return Fields.at(index);
		}
		catch(std::out_of_range)
		{
			return std::vector<uint8_t>();
		}
		return std::vector<uint8_t>();
	}

	int ComposerBox::GetInt(field_t index)
	{
		std::vector<uint8_t> vec = ComposerBox::GetVector(index);
		int val = 0;
		std::size_t size = vec.size();
		for (int i = 0; i < size; i++)
			val = (val << 8) | vec[i];
		return val;
	}

	void ComposerBox::Direct(field_t index, std::vector<uint8_t> field)
	{
		uint16_t size = field.size() + 4;
		std::vector<uint8_t> cmd(size);

		cmd.push_back((uint8_t)(size >> 8));
		cmd.push_back((uint8_t)size);

		cmd.push_back(MyIndex);
		cmd.push_back(index);

		Directs[index] = cmd;
		Composer.IndexingBox(MyIndex);
	}
}