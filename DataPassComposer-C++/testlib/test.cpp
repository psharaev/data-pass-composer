#define CheckCompileLib
#ifdef CheckCompileLib

#include <iostream>
#include "DataPassComposer.h"
using namespace DataPassComposer;
using namespace std;

int main()
{
	Composer.setup(1, 1);

	ComposerBox Box;
	Composer.AddBox(Box);

	Composer.Parse(0x00);
	Composer.Parse(0x04);// 5 byte
	Composer.Parse(0x00);// 0 box
	Composer.Parse(0x00);// 0 field
	Composer.Parse(0xA2);// 162

	/*Composer.Parse(0x00);
	Composer.Parse(0x05);// 6 byte
	Composer.Parse(0x01);// 1 box
	Composer.Parse(0x01);// 1 field
	Composer.Parse(0x12);
	Composer.Parse(0x7B);// 4731*/

	cout << Composer.GetAmountBoxes() << " " << Composer.GetAmountFields() << endl;
	cout << Box.GetInt(0) << endl;
	cin.get();
	return 0;
}

#endif // CheckCompileLib