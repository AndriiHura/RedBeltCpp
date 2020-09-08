#include"rational.h"
#include "test_runner.h"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;



void TestDefaultConstructor() {
    const Rational defaultConstructed;
    ASSERT_EQUAL(defaultConstructed.Numerator(), 0);
    ASSERT_EQUAL(defaultConstructed.Denominator(), 1);
}

void TestConstruction() {
    const Rational r(3, 12);
    ASSERT_EQUAL(r.Numerator(), 1);
    ASSERT_EQUAL(r.Denominator(), 4);
}



int main()
{
    TestRunner tr;
    RUN_TEST(tr, TestConstruction);
    RUN_TEST(tr, TestDefaultConstructor);
    return 0;
}