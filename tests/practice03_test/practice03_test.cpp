#include "pch.h"
#include "CppUnitTest.h"
#include "../../practice/practice03/practice03.cpp";

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace practice03test
{
	TEST_CLASS(practice03test)
	{
	public:

		TEST_METHOD(Test_SumRange)
		{

			Assert::AreEqual(MathUtils::sumRange(1, 2), 3);
			Assert::AreEqual(MathUtils::sumRange(0, 0), 0);
			Assert::AreEqual(MathUtils::sumRange(1, 4), 10);
		}
		TEST_METHOD(Test_Contain_Negatives)
		{
			std::vector<int> values = { 3, -1, 5, 7 };

			Assert::AreEqual(MathUtils::containsNegative(values), true);
			Assert::AreEqual(MathUtils::containsNegative({ -1, -2, 3 }), true); 
			Assert::AreEqual(MathUtils::containsNegative({ 1, 2, 3 }), false);
		}
		TEST_METHOD(Test_Find_Max)
		{
			std::vector<int> values = { 3, -1, 5, 7 };
			std::vector<int> values2;

			Assert::AreEqual(MathUtils::findMax(values), 7);
			Assert::AreEqual(MathUtils::findMax({ 1, 2, 3 }), 3);
			/*Assert::ExpectException<std::invalid_argument>([&] { MathUtils::findMax(values2); });*/
		}

	};
}
