// Copyright 2021 Loganov Andrei
#include <gtest/gtest.h>
#include <tuple>
#include "include/complex_number.h"
TEST(Loganov_Andrei_ComplexNumberTest, arithmetic_op) {
    // initialization
    ComplexNumber n1(182.0, 17.0);
    ComplexNumber n2(3.0, 10.0);
    ComplexNumber n3(2.0, 2.0);
    ComplexNumber n4(1.0, 1.0);
    // calc
    ComplexNumber op = (n1+n2)*n3/n4;
    ComplexNumber Result(370, 54);
    // Assert
    EXPECT_EQ(op, Result);
}
TEST(Loganov_Andrei_ComplexNumberTest, CopyValue) {
    // initialization
    ComplexNumber a(10.0, 12.0);
    ComplexNumber b(a);
    // calc
    bool res = false;
    if ((b.getRe() == 10) && (b.getIm() == 12)) {
        res = true;
    }
    // Assert
    ASSERT_TRUE(res);
}
using Loganov_Parametrized
= testing::TestWithParam<std::tuple< double, double>>;
TEST_P(Loganov_Parametrized, MultByConstPARAM) {
    // initialization
    const double co = 2;
    ComplexNumber numb1(std::get<0>(GetParam()), std::get<1>(GetParam()));
    // calc
    ComplexNumber result(numb1.getRe()*co, numb1.getIm()*co);
    result = result - numb1;
    // Assert
    ASSERT_EQ(result, numb1);
}
INSTANTIATE_TEST_CASE_P(/**/, Loganov_Parametrized, testing::Combine(
  testing::Values(2.0, 1.0),
  testing::Values(1.0, 8.0)
));
