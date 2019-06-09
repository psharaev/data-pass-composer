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

	/*private*/ void ComposerClass::IndexingBox(uint16_t index)
	{
		ComposerClass::IndexBoxDirect.insert(index);
	}

	/*private*/ void ComposerClass::ProcessCommand()
	{
		try
		{
			ComposerClass::ComposerBoxes.at(CommandIndexBox());
		}
		catch (std::out_of_range)
		{
			if (ComposerClass::NotImplementedFunc != nullptr)
			{
				NotImplementedFunc(CommandIndexBox(), CommandIndexField(), CommandContent());
			}
			return;
		}
		
		ComposerClass::ComposerBoxes[CommandIndexBox()]->SetField(CommandIndexField(), CommandContent());
	}

	/*private*/ box_t ComposerClass::CommandIndexBox()
	{
		uint16_t val = 0;
		for (int i = 2; i < 2 + BoxBytes; i++)
			val = (val << 8) | ComposerClass::Command[i];
		return val;
	}

	/*private*/ field_t ComposerClass::CommandIndexField()
	{
		uint16_t val = 0;
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

	bool ComposerClass::AddBox(ComposerBox & box, box_t index)
	{
		ComposerClass::ComposerBoxes[index] = &box;
		box.AddBox(index);
		return true;
	}

	bool ComposerClass::AddBoxForcibly(ComposerBox & box, box_t & index)
	{
		ComposerClass::ComposerBoxes[index] = &box;
		box.AddBox(index);
		return true;
	}

	bool ComposerClass::RemoveBox(ComposerBox & box)
	{
		return false;
	}

	bool ComposerClass::RemoveBox(box_t & box)
	{
		return false;
	}

	void ComposerClass::OnNotImplemented(void(*func)(box_t, field_t, std::vector<uint8_t>))
	{
		ComposerClass::NotImplementedFunc = func;
	}

	std::vector<uint8_t> ComposerClass::Transmit()
	{
		ComposerClass::IndexBoxDirect.clear();
		return std::vector<uint8_t>();
	}

	ComposerClass Composer;
}