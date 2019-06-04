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
		void SetField(uint16_t index, std::vector<uint8_t> vec);
	public:
		std::vector<uint8_t> GetVector(uint16_t index);
		int GetInt(uint16_t index);

		ComposerBox();
		~ComposerBox();

		friend class ComposerClass;
	};
}