#include "pch.h"
#include "CppUnitTest.h"
#include "C:\C++ projects\SE project\current build\main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestforSEproject
{
	TEST_CLASS(UnitTestforSEproject)
	{
	public:

		TEST_METHOD(TestcalculateY)
		{
			double x = -1.0;
			int n = 3;

			long double expected_y = -1.6666666666666667;

			long double actual_y = calculateY(x, n);

			Assert::AreEqual(expected_y, actual_y, 0.0001);
		}

	public:

		TEST_METHOD(CheckNum_b_get_a_smaller_than_b_exceptionNotThrown)
		{
			double a = 3;
			double b = 7;
			try {
				CheckNum_b(a, b);
				Assert::IsTrue(true);
			}
			catch (const char* ex) {
				Assert::Fail();
			}
		}
	public:

		TEST_METHOD(CheckNum_b_get_a_bigger_than_b_exceptionThrown)
		{
			double a = 15;
			double b = 7;
			try {
				CheckNum_b(a, b);
				Assert::Fail();
			}
			catch (...) {
				Assert::IsTrue(true);
			}
		}
	public:

		TEST_METHOD(CheckStepValue_get7_exceptionThrown)
		{
			double step = 7;
			try {
				CheckStepValue(step);
				Assert::IsTrue(true);
				
			}
			catch (...) {
				Assert::Fail();
			}
		}
	public:

		TEST_METHOD(CheckStepValue_get0_exceptionThrown)
		{
			double step = 0;
			try{
				CheckStepValue(step);
				Assert::Fail();
			}
			catch (...) {
				Assert::IsTrue(true);
			}
		}
	public:

		TEST_METHOD(n_Check_get_negative_x_and_n_bigger_than_3)
		{
			
			double x = -3;
			int n = 5;
			try {
				n_Check(x, n);
				Assert::IsTrue(true);
			}
			catch (...) {
				Assert::Fail();
			}
		}
	public:

		TEST_METHOD(n_Check_get_positive_x_and_n_smaller_than_3)
		{

			double x = 6;
			int n = 0;
			try {
				n_Check(x, n);
				Assert::Fail();
			}
			catch (...) {
				Assert::IsTrue(true);
			}
		}
	public:

		TEST_METHOD(n_Check_get_positive_x_and_n_bigger_than_0)
		{

			double x = 2;
			int n = 3;
			try {
				n_Check(x, n);
				Assert::IsTrue(true);
			}
			catch (...) {
				Assert::Fail();
			}
		}
	public:

		TEST_METHOD(n_Check_get_negative_x_and_negative_n)
		{

			double x = -4;
			int n = -2;
			try {
				n_Check(x, n);
				Assert::Fail();
			}
			catch (...) {
				Assert::IsTrue(true);
			}
		}
	};
}
