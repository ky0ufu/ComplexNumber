#include "gtest/gtest.h"
#include "../lib/ComplexNumber/ComplexNumber.h"


TEST(ComplexNumberTest, ConstructorTest)
{
    ComplexNumber number;

    bool correct = (are_equal(number.get_real(), 0.0) && are_equal(number.get_imag(), 0.0));

    ASSERT_TRUE(correct);
}

TEST(ComplexNumberTest, ConstructorParamTest)
{
    ComplexNumber number(3.14f);

    bool correct = (are_equal(number.get_real(), 3.14f) && are_equal(number.get_imag(), 0.0));

    ASSERT_TRUE(correct);
}

TEST(ComplexNumberTest, ConstructorParam2Test)
{
    ComplexNumber number(-3.743, 9.12);

    bool correct = (are_equal(number.get_real(), -3.743) && are_equal(number.get_imag(), 9.12));

    ASSERT_TRUE(correct);
}

TEST(ComplexNumberTest, GetRealTest)
{
    ComplexNumber number(3.14);

    bool correct_real = are_equal(number.get_real(), 3.14);

    ASSERT_TRUE(correct_real);
}

TEST(ComplexNumberTest, GetImagTest)
{
    ComplexNumber number(2.71, 7.1);

    bool correct_imag = are_equal(number.get_imag(), 7.1);

    ASSERT_TRUE(correct_imag);
}

TEST(ComplexNumberTest, SetRealTest)
{
    ComplexNumber number;

    number.set_real(2.71);

    bool correct_real = are_equal(number.get_real(), 2.71);

    ASSERT_TRUE(correct_real);
}

TEST(ComplexNumberTest, SetImagTest)
{
    ComplexNumber number;

    number.set_imag(2.71);

    bool correct_imag = are_equal(number.get_imag(), 2.71);

    ASSERT_TRUE(correct_imag);
}

TEST(ComplexNumberTest, ToStringTest)
{
    ComplexNumber number(8, 9);

    bool correct = number.to_string() == "8.000000+9.000000i";

    ASSERT_TRUE(correct);
}

TEST(ComplexNumberTest, ABSTest)
{
    ComplexNumber number(6, 8);

    bool correct_abs = are_equal(number.abs(), 10);

    ASSERT_TRUE(correct_abs);
}

TEST(ComplexNumberTest, PowTest)
{
    ComplexNumber number(3, 4);
    int exp = 3;

    bool correct_pow = number.pow(exp) == ComplexNumber(-117, 44);

    ASSERT_TRUE(correct_pow);
}

TEST(ComplexNumberTest, SumTest)
{
    bool correct_sum = ComplexNumber(5, 3) + ComplexNumber(3, 12) == ComplexNumber(8, 15);

    ASSERT_TRUE(correct_sum);
}

TEST(ComplexNumberTest, SubTest)
{
    bool correct_sub = ComplexNumber(9, 2) - ComplexNumber(4, 1) == ComplexNumber(5, 1);

    ASSERT_TRUE(correct_sub);
}

TEST(ComplexNumberTest, MulTest)
{
    bool correct_mul = ComplexNumber(1, 2) * ComplexNumber(3, 4) == ComplexNumber(-5, 10);

    ASSERT_TRUE(correct_mul);
}

TEST(ComplexNumberTest, DivTest)
{
    bool correct_div = ComplexNumber(1, 2) / ComplexNumber(3, 4) == ComplexNumber(0.44, 0.08);

    ASSERT_TRUE(correct_div);
}

TEST(ComplexNumberTest, EqualTest)
{
    bool correct_equal = ComplexNumber(15, -21) == ComplexNumber(15, -21);

    ASSERT_TRUE(correct_equal);
}

TEST(ComplexNumberTest, NotEqualTest)
{
    bool correct_ans = ComplexNumber(15, -21) != ComplexNumber(-15, 21);

    ASSERT_TRUE(correct_ans);
}