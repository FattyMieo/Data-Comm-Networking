#pragma once
#include "TypeDefinition.h"
#define DATACOUNT 4

class Package
{
private:
	uint values[DATACOUNT];
	uint bits[DATACOUNT];

	void InitializeBitCount();

public:
	Package();
	Package(uint num1, uint num2, uint num3, uint num4);
	virtual ~Package();

	ushort Pack();
	void Unpack(ushort data);
	void Print();
};
