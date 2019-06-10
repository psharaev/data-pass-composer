#include <iostream>
#include "DataPassComposer.h"
#include "ExtensionMethods.h"
using namespace DataPassComposer;
using namespace std;

void kek(box_t b, field_t f, std::vector<uint8_t> c)
{
	cout << (int)b << " " << (int)f << " " << system::To<int>(c) << endl;
}

int main()
{
	Composer.OnNotImplemented(kek);
	ComposerBox BoxFF;
	ComposerBox BoxA;
	ComposerBox BoxSender;
	Composer.AddBoxForcibly(BoxFF,0xFF);
	Composer.AddBoxForcibly(BoxA,0x0A);
	Composer.AddBoxForcibly(BoxSender, 0xFFF);

	Composer.Parse(Composer.Transmit());

	cin.get();
	return 0;
}