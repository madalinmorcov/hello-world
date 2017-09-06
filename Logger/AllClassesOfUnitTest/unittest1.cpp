#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Logger/ILog.h"
#include "../Logger/ILog.cpp"
#include <cassert>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AllClassesOfUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestLogging)
		{
			Logging x;
			bool isGoooood = true;


			try {
				x.Log(ErrorType::ERROR, "asdasdasdasdasdasd");
			}
			catch(char *e)
			{
				isGoooood = false;
			}

			Assert::IsTrue(isGoooood);
		}

		TEST_METHOD(TestTimerStart)
		{
			TimerWrapper x;
			bool isGoooood = true;


			try {
				x.startTimer("asd");
			}
			catch (char *e)
			{
				isGoooood = false;
			}

			Assert::IsTrue(isGoooood);
		}
		TEST_METHOD(TestTimerStop)
		{
			TimerWrapper x;
			bool isGoooood = true;
			x.startTimer("asd");

			try {
				x.stopTimer("asd");
			}
			catch (char *e)
			{
				isGoooood = false;
			}

			Assert::IsTrue(isGoooood);
		}
	};
}