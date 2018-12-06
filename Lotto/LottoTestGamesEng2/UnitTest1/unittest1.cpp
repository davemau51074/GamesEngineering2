#include "stdafx.h"
#include "CppUnitTest.h"
#include "../LottoTestGamesEng2/main.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestValidNumbers)
		{
			std::vector<int> nums;
			nums.push_back(1);
			nums.push_back(2);
			nums.push_back(3);
			nums.push_back(4); 
			nums.push_back(5);
			nums.push_back(6);
			Assert::AreEqual(true, testNumbers(nums));
		}

		TEST_METHOD(TestNotValidNumbers)
		{
			std::vector<int> nums;
			nums.push_back(1);
			nums.push_back(20);
			nums.push_back(37);
			nums.push_back(45);
			nums.push_back(59);
			nums.push_back(69);
			Assert::AreEqual(false, testNumbers(nums));
		}

		TEST_METHOD(RepeatedNumbers)
		{
			std::vector<int> nums;
			nums.push_back(1);
			nums.push_back(2);
			nums.push_back(3);
			nums.push_back(4);
			nums.push_back(1);
			nums.push_back(6);
			Assert::AreEqual(false, testNumbers(nums));
		}

		TEST_METHOD(sevenNumbers)
		{
		
			std::vector<int> nums;
			nums.push_back(1);
			nums.push_back(2);
			nums.push_back(3);
			nums.push_back(4);
			nums.push_back(5);
			nums.push_back(6);
			nums.push_back(7);
			Assert::AreEqual(false, testNumbers(nums));
		
		}

	};
}