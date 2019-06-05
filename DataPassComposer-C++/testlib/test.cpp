#define CheckCompileLib
#ifdef CheckCompileLib

#include <iostream>
#include "DataPassComposer.h"
using namespace DataPassComposer;
using namespace std;

int main()
{
	Composer.setup(1, 1);

	ComposerBox Box0;
	ComposerBox Box1;
	Composer.AddBox(Box0);
	Composer.AddBox(Box1);

	Composer.Parse(0x00);
	Composer.Parse(0x06);// 6 byte
	Composer.Parse(0x00);// 0 box
	Composer.Parse(0x00);// 0 field
	Composer.Parse(0x00);// 9
	Composer.Parse(0xFF);// 255
	cout << Box0.GetInt(0) << endl;

	Composer.Parse(0x00);
	Composer.Parse(0x06);// 6 byte
	Composer.Parse(0x01);// 0 box
	Composer.Parse(0x00);// 0 field
	Composer.Parse(0x00);// 9
	Composer.Parse(0x12);// 255
	cout << Box1.GetInt(0) << endl;

	Composer.Parse(0x00);
	Composer.Parse(0x06);// 6 byte
	Composer.Parse(0x00);// 1 box
	Composer.Parse(0x01);// 1 field
	Composer.Parse(0x12);
	Composer.Parse(0x7B);// 4731*/
	cout << Box0.GetInt(1) << endl;

	Composer.Parse(0x00);
	Composer.Parse(0x06);// 6 byte
	Composer.Parse(0x00);// 0 box
	Composer.Parse(0x00);// 0 field
	Composer.Parse(0x00);// 9
	Composer.Parse(0x0F);// 15
	cout << Box0.GetInt(0) << endl;
	
	cin.get();
	return 0;
}

#endif // CheckCompileLib