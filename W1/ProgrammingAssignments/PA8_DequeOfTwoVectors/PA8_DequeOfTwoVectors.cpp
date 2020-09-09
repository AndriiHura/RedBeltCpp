#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
//#include "test_runner.h"

using namespace std;

template<typename T>
class Deque {
public:
    Deque() : size_f_(0), size_b_(0) {}

    bool Empty() const {
        return p_back.empty() && p_front.empty();
    }

    size_t Size() const {
        return size_f_ + size_b_;
    }

    T& operator[](size_t index) {
        if (index >= size_f_) {
            return p_back[index - size_f_];
        }
        else {
            return p_front[size_f_ - index -1];
        }
    }

    const T& operator[](size_t index) const {
        if (index >= size_f_) {
            return p_back[index - size_f_];
        }
        else {
            return p_front[size_f_ - index - 1];
        }
    }

    T& At(size_t index) {
        if (index >= Size() || index < 0) {
            throw out_of_range("Wrong Index");
        }
        else {
            if (index >= size_f_) {
                return p_back[index - size_f_];
            }
            else {
                return p_front[size_f_ - index - 1];
            }
        }
    }

    const T& At(size_t index) const {
        if (index >= Size() || index < 0) {
            throw out_of_range("Wrong Index");
        }
        else {
            if (index >= size_f_) {
                return p_back[index - size_f_];
            }
            else {
                return p_front[size_f_ - index - 1];
            }
        }
    }

    T& Front() {
        if (size_f_ != 0)
        {
            return p_front.back();
        }
        else {
            return p_back.front();
        }
    }

    const T& Front() const {
        if (size_f_ != 0)
        {
            return p_front.back();
        }
        else {
            return p_back.front();
        }
    }

    T& Back() {
        if (size_b_ != 0)
        {
            return p_back.back();
        }
        else {
            return p_front.front();
        }
    }

    const T& Back() const {
        if (size_b_ != 0)
        {
            return p_back.back();
        }
        else {
            return p_front.front();
        }
    }

    void PushFront(const T& value) {
        p_front.push_back(value);
        ++size_f_;
    }

    void PushBack(const T& value) {
        p_back.push_back(value);
        ++size_b_;
    }

private:
    vector<T> p_front;
    vector<T> p_back;
    size_t size_f_;
    size_t size_b_;
};
//
//void TestDeque() {
//    Deque<int> d;
//    ASSERT(d.Empty());
//    ASSERT_EQUAL(d.Size(), 0);
//
//    d.PushBack(1);
//    d.PushBack(2);
//    ASSERT(!d.Empty());
//    ASSERT_EQUAL(d.Size(), 2);
//    ASSERT_EQUAL(d.Back(), 2);
//    ASSERT_EQUAL(d.Front(), 1);
//
//    d.PushFront(4);
//    d.PushFront(7);
//    ASSERT_EQUAL(d.Back(), 2);
//    ASSERT_EQUAL(d.Front(), 7);
//    ASSERT_EQUAL(d.Size(), 4);
//
//    ASSERT_EQUAL(d.At(0), 7);
//    ASSERT_EQUAL(d.At(3), 2);
//
//    ASSERT_EQUAL(d[0], 7);
//    ASSERT_EQUAL(d[3], 2);
//
//}
//
//int main()
//{
//    TestRunner tr;
//    RUN_TEST(tr, TestDeque);
//
//    Deque<int> d1;
//    d1.PushFront(2);
//    d1.PushFront(1);
//    d1.PushBack(3);
//    d1.PushBack(4);
//    cout << d1[2] << endl;
//
//    return 0;
//    return 0;
//}
