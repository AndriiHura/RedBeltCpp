#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stdexcept>
#include <set>
#include "test_runner.h"

using namespace std;

template <class T>
class ObjectPool {
public:
	T* Allocate() {
		if (!released.empty()) {
			auto front = released.front();
			allocated.insert(front);
			released.pop();
			return front;
		}
		
		T* object = new T;
		allocated.insert(object);
		return object;
	}

	T* TryAllocate() {
		if (!released.empty()) {
			auto front = released.front();
			allocated.insert(front);
			released.pop();
			return front;
		}
		return nullptr;
	}

	void Deallocate(T* object) {
		auto move = allocated.find(object);
		if (move == allocated.end()) {
			throw invalid_argument("");
		}

		released.push(*move);
		allocated.erase(move);
	}

	~ObjectPool() {
		for (auto& el : allocated) {
			delete el;
		}

		while (!released.empty()) {
			auto remove = released.front();
			delete remove;
			released.pop();
		}

	}

private:
	set<T*> allocated;
	queue<T*> released;
};

void TestObjectPool() {
	ObjectPool<string> pool;

	auto p1 = pool.Allocate();
	auto p2 = pool.Allocate();
	auto p3 = pool.Allocate();

	*p1 = "first";
	*p2 = "second";
	*p3 = "third";

	pool.Deallocate(p2);
	ASSERT_EQUAL(*pool.Allocate(), "second");

	pool.Deallocate(p3);
	pool.Deallocate(p1);
	ASSERT_EQUAL(*pool.Allocate(), "third");
	ASSERT_EQUAL(*pool.Allocate(), "first");

	pool.Deallocate(p1);
}

int main() {
	TestRunner tr;
	RUN_TEST(tr, TestObjectPool);
	return 0;
}
