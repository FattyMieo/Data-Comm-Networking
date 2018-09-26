#pragma once
#include "TypeDefinition.h"

template <typename T>
class DataSplitter
{
private:
	byte m_bytes[sizeof(T)];
	const byte byteMask = (byte)255;

public:
	byte* GetArray();
	void Split(T value); //store "1 unsigned int" value into "4 bytes"
	T Merge(void); //merge the bytes amd return the unsigned int value
};

template<typename T>
inline byte * DataSplitter<T>::GetArray()
{
	return m_bytes;
}

template<typename T>
inline void DataSplitter<T>::Split(T value)
{
	for (int i = 0; i < sizeof(T); i++)
	{
		m_bytes[i] = (byte)(value & byteMask);

		value = value >> 8;
	}
}

template<typename T>
inline T DataSplitter<T>::Merge(void)
{
	uint ret = 0;

	for (int i = 0; i < sizeof(T); i++)
	{
		ret = m_bytes[i] & byteMask;

		ret = ret << 8;
	}

	return ret;
}
