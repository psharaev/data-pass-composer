#include "DataPassComposer.h"
namespace DataPassComposer
{
	uint32_t MailComposerClass::AmountClients = 0;
	uint32_t MailComposerClass::AmountBoxes = 0;

	MailComposerClass::MailComposerClass()
	{

	}

	void MailComposerClass::begin(uint32_t AmountClients, uint32_t AmountBoxes)
	{
		MailComposerClass::AmountClients = AmountClients;
		MailComposerClass::AmountBoxes = AmountBoxes;
	}

	uint32_t MailComposerClass::GetAmountClients()
	{
		return MailComposerClass::AmountClients;
	}

	uint32_t MailComposerClass::GetAmountBoxes()
	{
		return MailComposerClass::AmountBoxes;
	}

	MailComposerClass MailComposer;
}