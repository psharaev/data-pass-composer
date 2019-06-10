#pragma once
#include <vector>
namespace DataPassComposer
{
	namespace system
	{
		struct ShellVectoruint8_t
		{
			std::vector<uint8_t> v;
			template<typename int> int To() {};
		};

		template<typename T> T To(const std::vector<uint8_t>& v);
		template<> int To(const std::vector<uint8_t>& v) {
			int val = 0;
			std::size_t size = v.size();
			for (int i = 0; i < size; i++)
				val = (val << 8) | v[i];
			return val;
		}
	}
}