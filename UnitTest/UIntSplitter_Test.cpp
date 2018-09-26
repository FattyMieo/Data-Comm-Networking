#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Data-Comm-Networking/UIntSplitter.h"
#include "../Data-Comm-Networking/UIntSplitter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UIntSplitter_Test)
	{
	public:

		TEST_METHOD(SplitterExpectsZeroesWhenInit)
		{
			UIntSplitter splitter;
			byte* splitterArray = splitter.GetArray();
			Assert::IsNotNull(splitterArray);
			Assert::AreEqual(splitterArray[0], (byte)0);
		}

		TEST_METHOD(SplitterByteMaskIsCorrect)
		{
			Assert::AreEqual(UIntSplitter::byteMaskz, (const byte)11111111);
		}

		TEST_METHOD(SplitterSplitsAndMerges)
		{
			UIntSplitter splitter;
			splitter.Split(123456);

			Assert::AreEqual(splitter.Merge(), (uint)123456);
		}

		TEST_METHOD(SplitterSplitsValue)
		{
			Assert::IsTrue(false);
		}

		TEST_METHOD(SplitterMergesBytes)
		{
			Assert::IsTrue(false);
		}

		TEST_METHOD(PackerSplitsAndMerges)
		{
			Assert::IsTrue(false);
		}

	};
}