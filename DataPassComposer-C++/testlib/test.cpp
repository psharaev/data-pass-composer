#define CheckCompileLib
#ifdef CheckCompileLib

#include <iostream>
#include "DataPassComposer.h"
using namespace DataPassComposer;
using namespace std;

int main()
{
	MailComposer.begin(2, 5);
	cout << MailComposer.GetAmountClients() << " " << MailComposer.GetAmountBoxes() << endl;
	cin.get();
	return 0;
}

#endif // CheckCompileLib