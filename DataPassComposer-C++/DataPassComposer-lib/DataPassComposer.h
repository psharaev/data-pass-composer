#pragma once
#include <cstdint>
#include <vector>
#include <map>
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
		static std::map<uint16_t, std::vector<uint8_t>> ComposerBoxes;

		static void ProcessCommand();
		static uint16_t CommandIndexBox();
		static uint16_t CommandIndexField();
		static std::vector<uint8_t> CommandContent();
	public:
		ComposerClass();
		static bool setup(uint8_t AmountBoxBytes, uint8_t AmountFieldBytes);
		static uint16_t GetAmountBoxes();
		static uint16_t GetAmountFields();

		static void Parse(uint8_t cmd);
		/*static void Parse(int cmd);
		static void Parse(uint8_t cmd[]);
		static void Parse(int cmd[]);
		static void Parse(string cmd);*/

		static void AddBox(ComposerBox &box);
		static void DeleteBox(ComposerBox &box);

		friend class CompsoerBox;
	};

extern ComposerClass Composer;

}