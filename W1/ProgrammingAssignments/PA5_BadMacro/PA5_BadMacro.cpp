#include "test_runner.h"

#include <ostream>
using namespace std;

#define PRINT_VALUES(out, x, y) out << (x) << endl << (y) << endl

int main() {
    TestRunner tr;
    tr.RunTest([] {
        ostringstream output;
        PRINT_VALUES(output, 5, "red belt");
        ASSERT_EQUAL(output.str(), "5\nred belt\n");
        }, "PRINT_VALUES usage example1");

    tr.RunTest([] {
        ostringstream output;
        PRINT_VALUES(output,"Andrii Hura", "red belt");
        ASSERT_EQUAL(output.str(), "Andrii Hura\nred belt\n");
        }, "PRINT_VALUES usage example2");

    tr.RunTest([] {
        ostringstream output;
        PRINT_VALUES(output, "1\n", 2);
        ASSERT_EQUAL(output.str(), "1\n\n2\n");
        }, "PRINT_VALUES usage example3");

    tr.RunTest([] {
        ostringstream output;
        if (true)
        {
            PRINT_VALUES(output, "Andrii Hura", "red belt");
        }
        else {
            PRINT_VALUES(output, "Not Andrii Hura", "red belt");
        }
        ASSERT_EQUAL(output.str(), "Andrii Hura\nred belt\n");
        }, "PRINT_VALUES usage example4");
}
