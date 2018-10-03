// the purpose of this class is to test your understanding of bit operations 
// it's less common we need to split the int into smaller data type, but there are few cases you will need to do this
// for exp, you are sending(or storing) byte arrays(byte stream), in order to store the date type larger than byte, you will
// need to split it

#pragma once
#include "TypeDefinition.h"

class UIntSplitter
{
	//Why do we need this?
		//Easier to tranfser in byte array
private:
	byte m_bytes[sizeof(uint)];

public:
	static const byte byteMask = (byte)255;

	UIntSplitter();
	virtual ~UIntSplitter();

	byte* GetArray();
	void Split(uint value); //store "1 unsigned int" value into "4 bytes"
	uint Merge(void); //merge the bytes amd return the unsigned int value
};
