#include "pch.h"
#include "CppUnitTest.h"
#include "../6.2r/6.2r.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* first = nullptr, * last = nullptr;
			enqueue(first, last, 1);
			enqueue(first, last, 22);
			enqueue(first, last, 23);
			enqueue(first, last, 47);
			enqueue(first, last, 22);
			int a = 1;
			remove1(first, a, 0);
			Assert::AreEqual(first->info , 22);
		}
	};
}
