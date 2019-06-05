#include "DataPassComposer.h"

namespace DataPassComposer
{
#pragma region ComposerClass

	uint16_t ComposerClass::AmountBoxes = 0;
	uint16_t ComposerClass::AmountFields = 0;

	uint8_t ComposerClass::AmountBoxBytes = 1;
	uint8_t ComposerClass::AmountFieldBytes = 1;

	std::vector<uint8_t> ComposerClass::Command = std::vector<uint8_t>(64);
	uint16_t ComposerClass::CommandLength = 0;
	uint16_t ComposerClass::NumberByteParse = 0;

	std::map<uint16_t, ComposerBox*> ComposerClass::ComposerBoxes;
	uint16_t ComposerClass::CreatorComposerBoxesIterator = 0;

	ComposerClass::ComposerClass()
	{
		ComposerClass::ComposerBoxes.clear();
		ComposerClass::Command.clear();
	}

	bool ComposerClass::setup(uint8_t AmountBoxBytes, uint8_t AmountFieldBytes)
	{
		if (AmountBoxBytes * AmountFieldBytes == 0)
			return false;

		ComposerClass::AmountBoxBytes = AmountBoxBytes;
		ComposerClass::AmountFieldBytes = AmountFieldBytes;
		ComposerClass::AmountBoxes = (1 << (AmountBoxBytes * 8)) - 1;
		ComposerClass::AmountFields = (1 << (AmountFieldBytes * 8)) - 1;
		return true;
	}

	uint16_t ComposerClass::GetAmountBoxes()
	{
		return ComposerClass::AmountBoxes;
	}

	uint16_t ComposerClass::GetAmountFields()
	{
		return ComposerClass::AmountFields;
	}

	void ComposerClass::ProcessCommand()
	{
		ComposerClass::ComposerBoxes[CommandIndexBox()]->SetField(CommandIndexField(), CommandContent());
	}

	uint16_t ComposerClass::CommandIndexBox()
	{
		uint16_t val = 0;
		for (int i = 2; i < 2 + ComposerClass::AmountBoxBytes; i++)
			val = (val << 8) | ComposerClass::Command[i];
		return val;
	}

	uint16_t ComposerClass::CommandIndexField()
	{
		uint16_t val = 0;
		for (int i = 2 + ComposerClass::AmountBoxBytes; i < 2 + ComposerClass::AmountBoxBytes + ComposerClass::AmountFieldBytes; i++)
			val = (val << 8) | ComposerClass::Command[i];
		return val;
	}

	std::vector<uint8_t> ComposerClass::CommandContent()
	{
		std::vector<uint8_t> val = {};
		for (int i = 2 + ComposerClass::AmountBoxBytes + ComposerClass::AmountFieldBytes; i < ComposerClass::CommandLength; i++)
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

	bool ComposerClass::AddBox(ComposerBox & box)
	{
		ComposerClass::ComposerBoxes[ComposerClass::CreatorComposerBoxesIterator] = &box;
		ComposerClass::CreatorComposerBoxesIterator++;
		return true;
	}

	bool ComposerClass::AddBox(ComposerBox & box, uint16_t & index)
	{
		return false;
	}

	bool ComposerClass::AddBoxForcibly(ComposerBox & box, uint16_t & index)
	{
		return false;
	}

	bool ComposerClass::RemoveBox(ComposerBox & box)
	{
		return true;
	}

	bool ComposerClass::RemoveBox(uint16_t & box)
	{
		return false;
	}

	ComposerClass Composer;

#pragma endregion
}