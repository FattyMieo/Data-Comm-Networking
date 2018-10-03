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
			Assert::AreEqual(UIntSplitter::byteMask, (const byte)255);
		}

		TEST_METHOD(SplitterSplitsAndMerges_1)
		{
			UIntSplitter splitter;
			splitter.Split(255);

			Assert::AreEqual(splitter.GetArray()[0], (byte)255);
			Assert::AreEqual(splitter.GetArray()[1], (byte)0);
			Assert::AreEqual(splitter.GetArray()[2], (byte)0);
			Assert::AreEqual(splitter.GetArray()[3], (byte)0);
		}

		TEST_METHOD(SplitterSplitsAndMerges_2)
		{
			UIntSplitter splitter;
			splitter.Split(256);

			Assert::AreEqual(splitter.GetArray()[0], (byte)0);
			Assert::AreEqual(splitter.GetArray()[1], (byte)1);
			Assert::AreEqual(splitter.GetArray()[2], (byte)0);
			Assert::AreEqual(splitter.GetArray()[3], (byte)0);
		}

		TEST_METHOD(SplitterSplitsAndMerges_3a)
		{
			UIntSplitter splitter;
			splitter.Split(1);

			Assert::AreEqual(splitter.Merge(), (uint)1);
		}

		TEST_METHOD(SplitterSplitsAndMerges_3b)
		{
			UIntSplitter splitter;
			splitter.Split(255);

			Assert::AreEqual(splitter.Merge(), (uint)255);
		}

		TEST_METHOD(SplitterSplitsAndMerges_3c)
		{
			UIntSplitter splitter;
			splitter.Split(256);

			Assert::AreEqual(splitter.Merge(), (uint)256);
		}

		TEST_METHOD(SplitterSplitsAndMerges_4)
		{
			UIntSplitter splitter;
			splitter.Split(123456);

			Assert::AreEqual(splitter.Merge(), (uint)123456);
		}
	};
}