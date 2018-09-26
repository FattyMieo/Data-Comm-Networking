#include "UIntPacker.h"

UIntPacker::UIntPacker()
{
	m_data = 0;
	m_bitCount = 0;
}

UIntPacker::~UIntPacker()
{

}

bool UIntPacker::Pack(uint value, uint bitCount)
{
	//Unable to pack if there's not enough bits available
	if (m_bitCount + bitCount >= sizeof(uint) * 8)
	{
		return false;
	}

	m_data = m_data << bitCount;
	m_data = m_data | value;

	m_bitCount += bitCount;

	return true;
}

bool UIntPacker::Extract(uint& outValue, uint bitCount)
{
	//Unable to pack if there's not enough bits available
	if (m_bitCount - bitCount < 0)
	{
		return false;
	}

	uint mask = (1 << bitCount) - 1;
	outValue = m_data & mask;

	m_data = m_data >> bitCount;

	m_bitCount -= bitCount;

	return true;
}
