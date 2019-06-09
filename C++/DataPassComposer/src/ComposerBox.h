#pragma once
#include <cstdint>
#include <vector>
#include <map>
#include "Macros.h"

namespace DataPassComposer
{
	class ComposerBox
	{
	private:
		std::map<field_t, std::vector<uint8_t>> Fields;
		std::map<field_t, std::vector<uint8_t>> Directs;
		box_t MyIndex;

		void AddBox(box_t index);

		void SetField(field_t index, std::vector<uint8_t> vec);
		std::map<field_t, std::vector<uint8_t>>* GetDirects();
	public:
		ComposerBox();
		~ComposerBox();

		std::vector<uint8_t> GetVector(field_t index);
		int GetInt(field_t index);
		void Direct(field_t index, std::vector<uint8_t> field);

		friend class ComposerClass;
		friend class Composer;
	};
}