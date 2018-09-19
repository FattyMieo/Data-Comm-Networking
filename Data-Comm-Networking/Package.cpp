#include "Package.h"
#include <iostream>
#include <bitset>

using namespace std;

void Package::InitializeBitCount()
{
	bits[0] = 4;
	bits[1] = 1;
	bits[2] = 5;
	bits[3] = 1;
}

Package::Package()
{
	for (int i = 0; i < DATACOUNT; ++i)
	{
		values[i] = 0;
	}

	InitializeBitCount();
}

Package::Package(unsigned int num1, unsigned int num2, unsigned int num3, unsigned int num4)
{
	values[0] = num1;
	values[1] = num2;
	values[2] = num3;
	values[3] = num4;

	InitializeBitCount();
}

Package::~Package()
{

}
/*
__data16 Package::Pack()
{
	__data16 ret = 0;

	for (int i = 0; i < DATACOUNT; ++i)
	{
		ret = ret << bits[i];			//E.g. 1110110<----
		ret = ret | values[i];			//E.g. 1110110(1010)
	}

	return ret;
}

void Package::Unpack(__data16 data)
{
	for (int i = DATACOUNT - 1; i >= 0; --i) //Read in reverse
	{
		//Old
		//__data16 bitMask = 0 - 1;			//All ones
		//bitMask = bitMask << bits[i];		//E.g. 11111110000
		//bitMask = ~bitMask;				//E.g. 00000001111

		//Better alternative
		__data16 bitmask = (1 << bits[i]) - 1;	//E.g. 00000001111

		values[i] = data & bitMask;		//E.g.(0000000)1010
		data = data >> bits[i];			//E.g. 1110110---->
	}
}
*/

__data16 Package::Pack()
{
	__data16 ret = 0;

	for (int i = 0; i < DATACOUNT; ++i)
		ret = (ret << bits[i]) | values[i];

	return ret;
}

void Package::Unpack(__data16 data)
{
	for (int i = DATACOUNT - 1; i >= 0; --i)
	{
		//values[i] = data & ~(((__data16)0 - 1) << bits[i]);
		values[i] = data & (__data16)(1 << bits[i]) - 1;
		data = data >> bits[i];
	}
}

void Package::Print()
{
	for (int i = 0; i < DATACOUNT; ++i)
	{
		cout << values[i] << " ";
	}
}

void DebugBinary(__data16 data)
{
	std::bitset<sizeof(__data16) * 8> x(data); cout << x << endl; system("PAUSE");
}

void DebugBinary(unsigned int data)
{
	std::bitset<sizeof(unsigned int) * 8> x(data); cout << x << endl; system("PAUSE");
}
