#include "UIntSplitter.h"

UIntSplitter::UIntSplitter()
{
	for (int i = 0; i < sizeof(uint); ++i)
	{
		m_bytes[i] = 0;
	}
}

UIntSplitter::~UIntSplitter()
{

}

byte* UIntSplitter::GetArray()
{
	return m_bytes;
}

void UIntSplitter::Split(uint value)
{
	for (int i = 0; i < sizeof(uint); ++i)
	{
		m_bytes[i] = (byte)(value & byteMask);

		value = value >> 8;
	}
}

uint UIntSplitter::Merge(void)
{
	uint ret = 0;

	for (int i = sizeof(uint) - 1; i >= 0; --i)
	{
		ret = ret << 8;

		ret = ret | (uint)m_bytes[i];
	}

	return ret;
}
