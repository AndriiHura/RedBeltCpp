#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;


int main() {
	int numOfTest;
	cin >> numOfTest;
	for (int i = 0; i < numOfTest; ++i) {
		int numOfElements;
		cin >> numOfElements;
		
		vector<int> arr;
		for (int j = 0; j < numOfElements; ++j) {
			int currentElement;
			cin >> currentElement;
			arr.push_back(currentElement);
		}
		if (numOfElements <= 2) {
			cout << 0 << endl;;
			continue;
		}
		
		int numOfActions = 0;
		while (!arr.empty()) {
			auto itMax = max_element(arr.begin(), arr.end());
			auto itMin = min_element(arr.begin(), arr.end());
			
			//cout << *itMax << " " << *itMin << endl;
			int diff = min(abs(*itMax), abs(*itMin));
			*itMax -= diff;
			*itMin += diff;

			auto itRem = find(arr.begin(), arr.end(), 0);
			arr.erase(itRem);
			++numOfActions;
		}
		cout << numOfActions-1 << endl;;
		
	}
}