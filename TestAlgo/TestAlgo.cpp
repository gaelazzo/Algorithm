#include "pch.h"
#include "CppUnitTest.h"
#include "suffixtree.h"
#include "randomData.h"

#include <random>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace TestAlgo
{
	
	
	

	TEST_CLASS(TestAlgo)
	{
	public:
		TEST_METHOD_INITIALIZE(init)
		{
			// method initialization code
		}

		TEST_CLASS_CLEANUP(methodName)
		{
			// test class cleanup  code
		}

		TEST_METHOD(createRandomVectorGeneratesAVector)
		{
			vector<int> v = Algoritmi::createRandomVector(1000, 0.0,100.0);
			Assert::AreEqual((int) v.size(), 1000);
			v.clear();
			Assert::AreEqual((int)v.size(), 0);
		}
		TEST_METHOD(createRandomStringLowerGeneratesAString)
		{
			std::string s= Algoritmi::createRandomStringLower(1000);
			Assert::AreEqual((int) s.length(), 1000);
			cout << s;
		}
	};
}
