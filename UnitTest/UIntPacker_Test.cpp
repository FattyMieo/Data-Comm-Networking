#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Data-Comm-Networking/UIntPacker.h"
#include "../Data-Comm-Networking/UIntPacker.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UIntPacker_Test)
	{
	public:

		TEST_METHOD(PackerPacksOneBit)
		{
			UIntPacker packer;

			Assert::IsTrue(packer.Pack(1, 1));
		}

		TEST_METHOD(PackerExtractsOneBit)
		{
			UIntPacker packer;
			packer.Pack(1, 1);
			uint extracted;

			Assert::IsTrue(packer.Extract(extracted, 1));
		}

		TEST_METHOD(PackerProcessesOneBit)
		{
			UIntPacker packer;
			packer.Pack(1, 1);
			uint extracted;
			packer.Extract(extracted, 1);

			Assert::AreEqual(extracted, (uint)1);
		}

		TEST_METHOD(PackerPacksAndExtracts)
		{
			UIntPacker packer;
			packer.Pack(1, 1);
			packer.Pack(15, 4);
			packer.Pack(25, 5);
			packer.Pack(1, 2);

			unsigned int value4T; packer.Extract(value4T, 2);
			unsigned int value3T; packer.Extract(value3T, 5);
			unsigned int value2T; packer.Extract(value2T, 4);
			unsigned int value1T; packer.Extract(value1T, 1);

			Assert::AreEqual(value4T, (unsigned int)1);
			Assert::AreEqual(value3T, (unsigned int)25);
			Assert::AreEqual(value2T, (unsigned int)15);
			Assert::AreEqual(value1T, (unsigned int)1);
		}

	};
}