#define CheckCompileLib
#ifdef CheckCompileLib

#include <iostream>
#include "DataPassComposer.h"
using namespace DataPassComposer;
using namespace std;

int main()
{
	Composer.begin(2, 5);
	Composer.Parse(0xFF);
	Composer.Parse(0xFF);
	cout << Composer.GetAmountBoxes() << " " << Composer.GetAmountFields() << endl;
	cin.get();
	return 0;
}

#endif // CheckCompileLib