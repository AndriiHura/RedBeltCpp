#include <iostream>
#include<vector>
#include <algorithm>
#include<set>
#include <deque>

using namespace std;

template <typename Iterator>
class IteratorRange {
private:
	Iterator first, last;
public:
	IteratorRange(Iterator new_f, Iterator new_l)
		: first(new_f), last(new_l) {}

	Iterator begin() const { return first; }
	Iterator end() const { return last; }


};

template < typename Container>
auto Head(Container& v, size_t top) {
	return IteratorRange{ v.begin(), next(v.begin(), min(top, v.size())) };
}

template <typename T>
size_t RangeSize(IteratorRange<T> r) {
	return r.end() - r.begin();
}

template <typename Iterator>
IteratorRange<Iterator> MakeRange(
	Iterator begin, Iterator end
) {
	return IteratorRange<Iterator>{begin, end};
}

int main()
{
	vector<int> v = { 1,2,3,4,5 };
	for (int& x : Head(v, 3)) {
		cout << ++x << ' ';
	}cout << endl;

	set<int> nums = { 5, 7, 12, 8, 10, 5, 6, 1 };
	for (int x : Head(nums, 4)) {
		cout << x << ' ';
	}cout << endl;

	const deque<int> nums2 = { 5, 7, 12, 8, 10, 5, 6, 1 };
	for (int x : Head(nums2, 4)) {
		cout << x << ' ';
	}cout << endl;
	/*pair p1(7, false);
		pair<int, bool> p(5, true);

	IteratorRange second_half(v.begin() + v.size() / 2, v.end());*/
	/*for (int& x : Head(v, 3)) {
		cout << ++x << ' ';
	}cout << endl;

	for (int& x : v) {
		cout << x << ' ';
	}cout << endl;

	cout << RangeSize(Head(v, 3));*/

	/*auto second_half = MakeRange(v.begin() + v.size() / 2, v.end());

	for (int x : second_half) {
		cout << x << ' ';
	}*/



}