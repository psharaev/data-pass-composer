#include "ComposerBox.h"
#include "DataPassComposer.h"
#include <cstdint>
#include <vector>
using namespace std;
namespace DataPassComposer
{
	void ComposerBox::SetField(uint16_t index, std::vector<uint8_t> vec)
	{
		Fields[index] = vec;
	}

	std::vector<uint8_t> ComposerBox::GetVector(uint16_t index)
	{
		try
		{
			return Fields.at(index);
		}
		catch(std::out_of_range)
		{
			return std::vector<uint8_t>();
		}
		return std::vector<uint8_t>();
	}

	int ComposerBox::GetInt(uint16_t index)
	{
		std::vector<uint8_t> vec = ComposerBox::GetVector(index);
		int val = 0;
		std::size_t size = vec.size();
		for (int i = 0; i < size; i++)
			val = (val << 8) | vec[i];
		return val;
	}

	ComposerBox::ComposerBox()
	{
	}

	ComposerBox::~ComposerBox()
	{
	}
}