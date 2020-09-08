#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class SimpleVector {
public:
    explicit SimpleVector(size_t size) {
        data = new T[size];
    }

    ~SimpleVector() {
        delete[] data;
    }

    T& operator[](size_t index) {
        return data[index];
    }
private:
    T* data;

};

//void f() {
//    int a = 43;
//    int b = 71;
//}

int main()
{


   /* int c = 89;
    int* d = &c;
    int* e = d + 1;

    cout << d << endl << e << endl;*/


    /*int c = 89;
    for (int i = 0; i < 40; ++i) {
        f();
        int x = *(&c + i);
        cout << i << ' ' << x << endl;
    }*/


   /* SimpleVector<int> sv(5);

    cout << sv[12] << endl;*/

  /*  for (int i = 0; i < 5; ++i) {
        sv[i] = 5 - i;
    }

    for (int i = 0; i < 5; ++i) {
        cout<< sv[i] << ' ';
    }*/


    /*int x = 5;
    int* y = &x;
    *y = 7;
    cout << x << ' ' << *y;*/

    /*int a = 43;
    int b = 71;
    int c = 89;

    
    cout << *(&a + 1)<< ' ' << *(&c - 1)<<endl;*/
    return 0;
}
