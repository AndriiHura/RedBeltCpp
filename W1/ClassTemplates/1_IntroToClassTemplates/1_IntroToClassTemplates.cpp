#include <iostream>
#include <vector>

using namespace std;

struct PairOfStrAndInt {
    string first;
    int second;
};

template<typename T, typename U>
struct Pair {
    T first;
    U second;
};

int main()
{
    Pair<string, int> si;

    si.first = "Hello";
    si.second = 5;

    Pair<bool, char> bc;
    bc.first = true;
    bc.second = 's';

    /*PairOfStrAndInt si;
    si.first = "Hello";
    si.second = 5;*/
}