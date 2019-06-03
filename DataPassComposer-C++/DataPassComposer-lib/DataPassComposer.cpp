#include "DataPassComposer.h"
#include <iostream>
namespace DataPassComposer
{
	uint16_t ComposerClass::AmountBoxes = 0;
	uint16_t ComposerClass::AmountFields = 0;

	uint8_t ComposerClass::AmountBoxBytes = 1;
	uint8_t ComposerClass::AmountFieldBytes = 1;

	std::vector<uint8_t> ComposerClass::Command = std::vector<uint8_t>(64);
	uint16_t ComposerClass::CommandLength = 0;
	uint16_t ComposerClass::NumberByteParse = 0;

	ComposerClass::ComposerClass()
	{
		ComposerClass::Command.clear();
	}

	void ComposerClass::begin(uint16_t AmountBoxes, uint16_t AmountFields)
	{
		ComposerClass::AmountBoxes = AmountBoxes;
		ComposerClass::AmountFields = AmountFields;
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

	ComposerClass Composer;
}