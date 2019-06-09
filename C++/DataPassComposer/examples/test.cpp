#include <iostream>
#include "DataPassComposer.h"
using namespace DataPassComposer;
using namespace std;

void kek(box_t b, field_t f, std::vector<uint8_t> c)
{
	int val = 0;
	std::size_t size = c.size();
	for (int i = 0; i < size; i++)
		val = (val << 8) | c[i];
	cout << (int)b << " " << (int)f << " " << val << endl;
}

int main()
{
	Composer.OnNotImplemented(kek);
	//ComposerBox Box0;
	//ComposerBox Box1;
	//Composer.AddBox(Box0,0);
	//Composer.AddBox(Box1,1);

	Composer.Parse(0x00);
	Composer.Parse(0x06);// 6 byte
	Composer.Parse(0x00);// 0 box
	Composer.Parse(0x00);// 0 field
	Composer.Parse(0x00);// 9
	Composer.Parse(0xFF);// 255
	//cout << Box0.GetInt(0) << endl;

	Composer.Parse(0x00);
	Composer.Parse(0x06);// 6 byte
	Composer.Parse(0x01);// 0 box
	Composer.Parse(0x00);// 0 field
	Composer.Parse(0x00);// 9
	Composer.Parse(0x12);// 255
	//cout << Box1.GetInt(0) << endl;

	Composer.Parse(0x00);
	Composer.Parse(0x06);// 6 byte
	Composer.Parse(0x00);// 1 box
	Composer.Parse(0x01);// 1 field
	Composer.Parse(0x12);
	Composer.Parse(0x7B);// 4731
	//cout << Box0.GetInt(1) << endl;

	Composer.Parse(0x00);
	Composer.Parse(0x06);// 6 byte
	Composer.Parse(0x00);// 0 box
	Composer.Parse(0x00);// 0 field
	Composer.Parse(0x00);// 9
	Composer.Parse(0x0F);// 15
	//cout << Box0.GetInt(0) << endl;

	//Box0.Direct(15, { 0x12,0x12 });

	cin.get();
	return 0;
}