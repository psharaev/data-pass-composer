#pragma once
#include <cstdint>
#include <vector>
using namespace std;

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

		static void ProcessCommand();

	public:
		ComposerClass();
		static void begin(uint16_t AmountBoxes, uint16_t AmountFields);
		static uint16_t GetAmountBoxes();
		static uint16_t GetAmountFields();

		static void Parse(uint8_t cmd);
		/*static void Parse(int cmd);
		static void Parse(uint8_t cmd[]);
		static void Parse(int cmd[]);
		static void Parse(string cmd);*/

	};

extern ComposerClass Composer;

}