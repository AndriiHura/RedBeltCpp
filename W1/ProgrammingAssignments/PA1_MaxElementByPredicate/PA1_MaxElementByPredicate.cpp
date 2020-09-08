
#include <numeric>
#include <iterator>
#include <algorithm>
#include<vector>
#include<string>
#include <iostream>

using namespace std;

template<typename ForwardIterator, typename UnaryPredicate>
ForwardIterator max_element_if1(
    ForwardIterator first, ForwardIterator last, UnaryPredicate pred) {
    auto newEndIt = partition(first, last, pred);
    if (newEndIt != first) {
        return max_element(first, newEndIt);
    }
    else {
        return last;
    }
}

template<typename ForwardIterator, typename UnaryPredicate>
ForwardIterator max_element_if(
    ForwardIterator first, ForwardIterator last, UnaryPredicate pred) {
    auto resultIt = find_if(first, last, pred);
    for (auto cur = resultIt; cur != last; ++cur) {
        if (*resultIt < *cur && pred(*cur)) {
            resultIt = cur;
        }
    }
    return resultIt;
}


int main() {
    vector<string> vec = { "aaaa", "bbbb", "aaaaa", "cccccc", "zzz", "zzzzz" };
    auto it = max_element_if(vec.begin(), vec.end(), [](const string& str) {
        return str.length() >= 5;
        });
    cout << *it;
    return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
