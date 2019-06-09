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

		static void IndexingBox(uint16_t index);
	public:
		ComposerClass();

		static void Parse(uint8_t cmd);

		static bool AddBox(ComposerBox & box, box_t index);
		static bool AddBoxForcibly(ComposerBox & box, box_t & index);
		static bool RemoveBox(ComposerBox & box);
		static bool RemoveBox(box_t & box);

		static void OnNotImplemented(void(*func)(box_t, field_t,std::vector<uint8_t>));

		static std::vector<uint8_t> Transmit();

		friend class ComposerBox;
	};

	extern ComposerClass Composer;

}