#include <iostream>
#include <vector>

using namespace std;

template<typename Iter>
void PrintVector(Iter start, Iter end){
    for(auto st = start; st != end; ++st){
        cout<<*st<<" ";
    }
    cout <<endl;
}

int main() {
    vector<string> vec = {"Hello", ",", "my", "name", "is", "Andrii", "!"};
    PrintVector(vec.begin(), vec.end());
    return 0;
}
