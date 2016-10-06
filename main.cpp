/**
 * @brief   Getting started with the gtest libraries.
 * @note    - Add the following to Project>Properties>C/C++ Build>Settings>GCC G++ linker>Libraries (-l):
 *              - gtest
 *              - gtest_main
 *              - pthread
 *          - Select Google Testing in Run>Run Configuration>C/C++ Unit Test>testTest>C/C++ Testing and click Apply then Run
 */

#include <stdint.h>
#include <gtest/gtest.h>


class ExampleClass
{
public:
	ExampleClass() : myVal(0) {};
	uint8_t doSomething(uint8_t input)
	{
		myVal += input;
		return (input + 10);
	}

	uint32_t myVal;
};


TEST(ExampleTest, ShouldAddTen)
{
	// setup class
	ExampleClass myClass;

	//run tests
	EXPECT_EQ(0, myClass.myVal);
	EXPECT_EQ(1, myClass.myVal);  // If an EXPECT_ statement fails, the test carries on.
	EXPECT_EQ(13, myClass.doSomething(3));
	ASSERT_EQ(0, myClass.myVal);  // If an ASSERT_ statement fails, the function exits.
	EXPECT_EQ(3, myClass.myVal);
}
