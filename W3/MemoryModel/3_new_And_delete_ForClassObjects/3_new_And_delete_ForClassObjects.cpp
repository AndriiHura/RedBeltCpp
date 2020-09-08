#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

using namespace std;

struct Widget {
    Widget() {
        cout << "constructor" << endl;
    }

    ~Widget() {
        cout << "destructor" << endl;
    }
};

int main()
{
    Widget* pW = new Widget;
    delete pW;
}