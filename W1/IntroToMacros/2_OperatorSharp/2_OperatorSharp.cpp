#include"rational.h"
#include "test_runner.h"

#include <iostream>
#include <string>

using namespace std;

#define ASSERT_EQUAL(x, y, m) \
    AssertEqual(x, y, m)

void TestDefaultConstructor() {
    const Rational defaultConstructed;
    ASSERT_EQUAL(defaultConstructed.Numerator(), 0, "TestDefaultConstructor Numerator");
    ASSERT_EQUAL(defaultConstructed.Denominator(), 1, "TestDefaultConstructor Denominator");
}

void TestConstruction() {
    const Rational r(3, 12);
    ASSERT_EQUAL(r.Numerator(), 1, "TestConstruction Numerator");
    ASSERT_EQUAL(r.Denominator(), 4, "TestConstruction Denominator");
}

#define RUN_TEST(tr, func) \
    tr.RunTest(func, #func)

int main()
{
    TestRunner tr;
    RUN_TEST(tr, TestConstruction);
    RUN_TEST(tr, TestDefaultConstructor);
    return 0;
}