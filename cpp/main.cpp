#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

#include "sort.hpp"
#include "utils.hpp"

#include "List.hpp"
#include "Vector.hpp"
#include "Queue.hpp"
#include "Stack.hpp"

using namespace std;

template <typename T>
void printVector(const std::vector<T>& v) {
	for (T item : v) {
		std::cout << item << ' ';
	}
	std::cout << std::endl;
}

class GreaterThanInt {
	public:
		bool operator()(int lhs, int rhs) {
			return lhs > rhs;
		}
};

int main() {
	srand(time(nullptr));

	vector<int> v;
	for (int i = 1; i <= 100; i++) {
		v.push_back(i * rand());
	}

	printVector(v);
	cout << endl;

	mergeSort(v);

	printVector(v);
	cout << endl;

	mergeSort(v, GreaterThanInt());

	printVector(v);
	cout << endl;
}
