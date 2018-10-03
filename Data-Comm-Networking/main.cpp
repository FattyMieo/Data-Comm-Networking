#include <iostream>
#include <string>
#include "TypeDefinition.h"
#include "UIntPacker.h"
#include "UIntSplitter.h"

using namespace std;

int main(void)
{
	UIntPacker packer;
	packer.Pack(1, 1);
	packer.Pack(15, 4);
	packer.Pack(25, 5);
	packer.Pack(1, 2);

	unsigned int value1T = 0;
	unsigned int value2T = 0;
	unsigned int value3T = 0;
	unsigned int value4T = 0;

	packer.Extract(value4T, 2);
	packer.Extract(value3T, 5);
	packer.Extract(value2T, 4);
	packer.Extract(value1T, 1);

	cout << "value1T" << " = " << value1T << endl;
	cout << "value2T" << " = " << value2T << endl;
	cout << "value3T" << " = " << value3T << endl;
	cout << "value4T" << " = " << value4T << endl;

	system("PAUSE");

	packer.Pack(value1T, 1);
	packer.Pack(value2T, 4);
	packer.Pack(value3T, 5);
	packer.Pack(value4T, 2);

	cout << packer.GetData() << endl;

	UIntSplitter splitter;
	splitter.Split(packer.GetData());

	for (int i = 0; i < sizeof(uint); ++i)
	{
		cout << "m_byte[" << i << "] = " << (uint)splitter.GetArray()[i] << endl;
	}

	packer.SetData(splitter.Merge());

	packer.Extract(value4T, 2);
	packer.Extract(value3T, 5);
	packer.Extract(value2T, 4);
	packer.Extract(value1T, 1);

	cout << "value1T" << " = " << value1T << endl;
	cout << "value2T" << " = " << value2T << endl;
	cout << "value3T" << " = " << value3T << endl;
	cout << "value4T" << " = " << value4T << endl;

	system("PAUSE");

	return 0;
}
