#include <iostream>
#include <vector>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

vector<string> GenerateBigVector(){
    auto start = steady_clock::now();
    vector<string>result;
    for(int i = 0; i < 10000; ++i){
        result.insert(begin(result), to_string(i));
    }
    auto finish = steady_clock::now();
    auto duration = finish - start;
    cerr<<"Inner loop: " <<  duration_cast<milliseconds>(duration).count()<<endl;
    return result;
}
vector<string> GenerateBigVector(vector<string>& vec){
    auto start = steady_clock::now();
    for(int i = 0; i < 10000; ++i){
        vec.insert(begin(vec), to_string(i));
    }
    auto finish = steady_clock::now();
    auto duration = finish - start;
    cerr<<"Inner loop: " <<  duration_cast<milliseconds>(duration).count()<<endl;
    return vec;
}
vector<string> GenerateBigVector1(){
    vector<string>result;
    auto start = steady_clock::now();
    for(int i = 0; i < 30000; ++i){
        result.push_back(to_string(i));
    }
    auto finish = steady_clock::now();
    auto duration = finish - start;
    cerr<<"Inner loop: " <<  duration_cast<milliseconds>(duration).count()<<endl;
    return result;
}

int main() {
    vector<string> res;
    auto start = steady_clock::now();
    cout<<GenerateBigVector1().size()<<endl;
    auto finish = steady_clock::now();
    auto duration = finish - start;
    cerr<<"Total: "<< duration_cast<milliseconds>(duration).count()<<endl;

    return 0;
}
