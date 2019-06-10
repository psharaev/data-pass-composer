#pragma once
#include <cstdint>
#include <vector>
#include <map>
#include <set>
#include "Macros.h"
#include "ComposerBox.h"

namespace DataPassComposer
{
	class ComposerClass
	{
	private:
		static std::vector<uint8_t> Command;
		static uint16_t CommandLength;
		static uint16_t NumberByteParse;

		static std::map<box_t, ComposerBox*> ComposerBoxes;
		static std::set<box_t> IndexBoxDirect;

		static void(*NotImplementedFunc)(box_t, field_t, std::vector<uint8_t>);

		static void ProcessCommand();
		static box_t CommandIndexBox();
		static field_t CommandIndexField();
		static std::vector<uint8_t> CommandContent();

		static void IndexBox(box_t box_id);
	public:
		ComposerClass();

		static void Parse(uint8_t cmd);
		static void Parse(std::vector<uint8_t> cmd);

		static bool AddBox(ComposerBox & box, box_t box_id);
		static bool AddBoxForcibly(ComposerBox & box, box_t box_id);
		static bool RemoveBox(ComposerBox & box);
		static bool RemoveBox(box_t & box_id);

		static void OnNotImplemented(void(*func)(box_t, field_t,std::vector<uint8_t>));

		static std::vector<uint8_t> Transmit();
		static std::vector<uint8_t> Transmit(box_t box_id, field_t field_id, std::vector<uint8_t>);

		friend class ComposerBox;
	};

	extern ComposerClass Composer;

}