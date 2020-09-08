#include <iostream>
#include <algorithm>

using namespace std;

#define MAX(a, b)( a > b ? a : b)

#define SQR(x) ((x) * (x))

template <typename T>
T Sqr(T x) {
	return x * x;
}

int LogAndReturn(int x) {
	cout << "x = " << x << endl;
	return x;
}

#define SUM(x, y) x + y

int main() {
	cout << 2 * SUM(3, 5);
}
