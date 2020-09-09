#include "test_runner.h"

using namespace std;

// Реализуйте здесь шаблонный класс Table
template<typename T>
class Table {
public:
	Table(size_t rows, size_t cols)
		: rows_(rows), cols_(cols), table_(rows, vector<T>(cols)) {}

	vector<T>& operator[](size_t index) {
		return table_[index];
	}

	vector<T> operator[](size_t index) const {
		return table_[index];
	}

	void Resize(size_t new_rows, size_t new_cols) {
		table_.resize(new_rows);
		for (auto& v : table_) {
			v.resize(new_cols);
		}
		rows_ = new_rows;
		cols_ = new_cols;
	}

	pair<size_t, size_t> Size() const {
		if (rows_ * cols_ == 0) {
			return make_pair(0, 0);
		}
		return make_pair(rows_, cols_);
	}
private:
	size_t rows_;
	size_t cols_;
	vector<vector<T>> table_;

};

void TestTable() {
	Table<int> t(1, 1);
	ASSERT_EQUAL(t.Size().first, 1u);
	ASSERT_EQUAL(t.Size().second, 1u);
	t[0][0] = 42;
	ASSERT_EQUAL(t[0][0], 42);
	t.Resize(3, 4);
	ASSERT_EQUAL(t.Size().first, 3u);
	ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
	TestRunner tr;
	RUN_TEST(tr, TestTable);
	return 0;
}
