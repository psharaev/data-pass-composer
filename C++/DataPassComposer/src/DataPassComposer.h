#pragma once
#include <cstdint>
#include <vector>
#include <map>
#include <set>
#include "ComposerBox.h"

namespace DataPassComposer
{
	class ComposerClass
	{
	private:
		static uint16_t AmountBoxes, AmountFields;
		static uint8_t AmountBoxBytes, AmountFieldBytes;

		static std::vector<uint8_t> Command;
		static uint16_t CommandLength;
		static uint16_t NumberByteParse;

		static std::map<uint16_t, ComposerBox*> ComposerBoxes;
		static uint16_t CreatorComposerBoxesIterator;
		static std::set<uint16_t> IndexBoxDirect;

		static void ProcessCommand();
		static uint16_t CommandIndexBox();
		static uint16_t CommandIndexField();
		static std::vector<uint8_t> CommandContent();

		static void IndexingBox(uint16_t index);
	public:
		ComposerClass();

		static bool setup(uint8_t AmountBoxBytes, uint8_t AmountFieldBytes);
		static uint16_t GetAmountBoxes();
		static uint16_t GetAmountFields();

		static void Parse(uint8_t cmd);

		static bool AddBox(ComposerBox & box,uint16_t index);
		static bool AddBoxForcibly(ComposerBox & box, uint16_t & index);
		static bool RemoveBox(ComposerBox & box);
		static bool RemoveBox(uint16_t & box);

		static std::vector<uint8_t> Transmit();

		friend class ComposerBox;
	};

extern ComposerClass Composer;

}