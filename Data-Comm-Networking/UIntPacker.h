#pragma once
#include "TypeDefinition.h"

class UIntPacker
{
private:
	uint m_data;
	uint m_bitCount; //to count how many bits are used.

public:
	UIntPacker();
	virtual ~UIntPacker();

	//pack the "value" into m_data, it retuns true if there are enough bits available 
	//bitCount : the bit count of "value"
	bool Pack(uint inValue, uint bitCount);

	bool Extract(uint& outValue, uint bitCount);

	uint GetData();
	void SetData(uint data);
};
