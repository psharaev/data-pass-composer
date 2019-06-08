#pragma once
#include <cstdint>
#include <vector>
#include <map>

namespace DataPassComposer
{
	class ComposerBox
	{
	private:
		std::map<uint16_t, std::vector<uint8_t>> Fields;
		std::map<uint16_t, std::vector<uint8_t>> Directs;
		uint8_t MyIndex;

		void AddBox(uint16_t index);

		void SetField(uint16_t index, std::vector<uint8_t> vec);
		std::map<uint16_t, std::vector<uint8_t>>* GetDirects();
	public:
		ComposerBox();
		~ComposerBox();

		std::vector<uint8_t> GetVector(uint16_t index);
		int GetInt(uint8_t index);
		void Direct(uint8_t index, std::vector<uint8_t> field);

		friend class ComposerClass;
		friend class Composer;
	};
}