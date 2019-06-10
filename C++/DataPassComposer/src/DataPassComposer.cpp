#include "DataPassComposer.h"

namespace DataPassComposer
{
	std::vector<uint8_t> ComposerClass::Command = {};
	uint16_t ComposerClass::CommandLength = 0;
	uint16_t ComposerClass::NumberByteParse = 0;

	std::map<box_t, ComposerBox*> ComposerClass::ComposerBoxes = {};
	std::set<box_t> ComposerClass::IndexBoxDirect = {};

	void(*ComposerClass::NotImplementedFunc)(box_t, field_t, std::vector<uint8_t>) = nullptr;

	ComposerClass::ComposerClass()
	{
		ComposerClass::ComposerBoxes.clear();
		ComposerClass::Command.clear();
		ComposerClass::IndexBoxDirect.clear();
	}

	/*private*/ void ComposerClass::IndexBox(box_t box_id)
	{
		ComposerClass::IndexBoxDirect.insert(box_id);
	}

	/*private*/ void ComposerClass::ProcessCommand()
	{
		box_t box_id = CommandIndexBox();
		try
		{
			ComposerClass::ComposerBoxes.at(box_id);
		}
		catch (std::out_of_range)
		{
			if (ComposerClass::NotImplementedFunc != nullptr)
			{
				NotImplementedFunc(box_id, CommandIndexField(), CommandContent());
			}
			return;
		}

		ComposerClass::ComposerBoxes[box_id]->SetField(CommandIndexField(), CommandContent());
	}

	/*private*/ box_t ComposerClass::CommandIndexBox()
	{
		box_t val = 0;
		for (int i = 2; i < 2 + BoxBytes; i++)
			val = (val << 8) | ComposerClass::Command[i];
		return val;
	}

	/*private*/ field_t ComposerClass::CommandIndexField()
	{
		field_t val = 0;
		for (int i = 2 + BoxBytes; i < 2 + BoxBytes + FieldBytes; i++)
			val = (val << 8) | ComposerClass::Command[i];
		return val;
	}

	/*private*/ std::vector<uint8_t> ComposerClass::CommandContent()
	{
		std::vector<uint8_t> val = {};
		for (int i = 2 + BoxBytes + FieldBytes; i < ComposerClass::CommandLength; i++)
			val.push_back(ComposerClass::Command[i]);
		return val;
	}

	void ComposerClass::Parse(uint8_t cmd)
	{
		if (ComposerClass::NumberByteParse <= 1)
		{
			ComposerClass::Command.push_back(cmd);
			ComposerClass::NumberByteParse++;
			if (ComposerClass::NumberByteParse > 1)
				ComposerClass::CommandLength = (ComposerClass::Command[0] << 8) | ComposerClass::Command[1];
			return;
		}

		ComposerClass::Command.push_back(cmd);
		ComposerClass::NumberByteParse++;

		if (ComposerClass::NumberByteParse == ComposerClass::CommandLength)
		{
			ComposerClass::ProcessCommand();
			ComposerClass::CommandLength = 0;
			ComposerClass::NumberByteParse = 0;
			ComposerClass::Command.clear();
		}
	}

	void ComposerClass::Parse(std::vector<uint8_t> cmd)
	{
		if (!cmd.empty())
			for (auto& i : cmd)
				ComposerClass::Parse(i);
	}

	bool ComposerClass::AddBox(ComposerBox & box, box_t box_id)
	{
		try
		{
			ComposerClass::ComposerBoxes.at(box_id);
			return false;
		}
		catch (std::out_of_range) {}
		ComposerClass::ComposerBoxes[box_id] = &box;
		box.AddBox(box_id);
		return true;
	}

	bool ComposerClass::AddBoxForcibly(ComposerBox & box, box_t box_id)
	{
		ComposerClass::ComposerBoxes[box_id] = &box;
		box.AddBox(box_id);
		return true;
	}

	bool ComposerClass::RemoveBox(ComposerBox & box)
	{
		return false;
	}

	bool ComposerClass::RemoveBox(box_t & box_id)
	{
		return false;
	}

	void ComposerClass::OnNotImplemented(void(*func)(box_t, field_t, std::vector<uint8_t>))
	{
		ComposerClass::NotImplementedFunc = func;
	}

	std::vector<uint8_t> ComposerClass::Transmit()
	{
		std::vector<uint8_t> cmd = {};
		for (auto& i : ComposerClass::IndexBoxDirect)
		{
			for (auto& item : ComposerClass::ComposerBoxes[i]->Directs)
			{
				cmd.insert(cmd.end(), item.second.begin(), item.second.end());
			}
			ComposerClass::ComposerBoxes[i]->ClearDirects();
		}
		ComposerClass::IndexBoxDirect.clear();
		return cmd;
	}

	std::vector<uint8_t> ComposerClass::Transmit(box_t box_id, field_t field_id, std::vector<uint8_t>)
	{
		return std::vector<uint8_t>();
	}

	ComposerClass Composer;
}