#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
class SimpleVector {
public:
    explicit SimpleVector(size_t size) {
        data = new T[size];
        end_ = data + size;

    }

    ~SimpleVector() {
        delete[] data;
    }

    T& operator[](size_t index) {
        return data[index];
    }

    const T* begin() const {return data;}

    const T* end() const {return end_;}

     T* begin()  {return data;}

     T* end()  {return end_;}
private:
    T* data;
    T* end_;

};

template<typename T>
void Print(const SimpleVector<T>& v) {
    for (auto i = v.begin(); i != v.end(); ++i) {
        cout << *i << ' ';
    }
    cout << endl;
}


int main()
{
    SimpleVector<int> sv(4);
    sv[0] = 5;
    sv[1] = 3;
    sv[2] = 4;
    sv[3] = -1;

    sort(sv.begin(), sv.end());
    Print(sv);
    return 0;

}
