#pragma once
#define DATACOUNT 4

typedef unsigned short __data16;

class Package
{
private:
	unsigned int values[DATACOUNT];
	unsigned int bits[DATACOUNT];

	void InitializeBitCount();

public:
	Package();
	Package(unsigned int num1, unsigned int num2, unsigned int num3, unsigned int num4);
	virtual ~Package();

	__data16 Pack();
	void Unpack(__data16 data);
	void Print();
};
