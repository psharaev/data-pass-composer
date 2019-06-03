#pragma once
#include <cstdint>
using namespace std;

namespace DataPassComposer
{

	class MailComposerClass
	{
	private:
		static uint32_t AmountClients, AmountBoxes;

	public:
		MailComposerClass();
		static void begin(uint32_t AmountClients, uint32_t AmountBoxes);
		static uint32_t GetAmountClients();
		static uint32_t GetAmountBoxes();
	};

extern MailComposerClass MailComposer;

}