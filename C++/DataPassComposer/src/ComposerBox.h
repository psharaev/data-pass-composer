#pragma once
#include <cstdint>
#include <vector>
#include <map>
#include <set>
#include "Macros.h"

namespace DataPassComposer
{
	class ComposerBox
	{
	private:
		std::map<field_t, std::vector<uint8_t>> Fields;
		std::map<field_t, std::vector<uint8_t>> Directs;
		box_t this_box_id;

		void AddBox(box_t box_id);

		void SetField(field_t field_id, std::vector<uint8_t> vec);
		std::map<field_t, std::vector<uint8_t>>* GetDirects();
	public:
		ComposerBox();
		~ComposerBox();

		std::vector<uint8_t> GetBinary(field_t field_id);
		int GetInt(field_t field_id);

		bool Direct(field_t field_id, std::vector<uint8_t> data);
		void ClearDirects();

		friend class ComposerClass;
		friend class Composer;
	};
}