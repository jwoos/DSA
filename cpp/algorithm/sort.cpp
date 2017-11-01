#include <set>
#include <vector>
#include <utility>

template <typename T>
void insertionSort(std::vector<T>& v) {
	insertionSort(v, 0, v.size());
}

template <typename T>
void insertionSort(std::vector<T>& v, int start, int end) {
	for (int i = start + 1; i <= end; i++) {
		T temp = v[i];
		int j = i;

		while (j > start && temp < v[j - 1]) {
			v[j] = v[j - 1];
			j--;
		}

		v[j] = temp;
	}
}

template <typename T>
void merge(std::vector<T>& v, std::vector<T>& temp, int leftStart, int leftEnd, int rightEnd) {
	int rightStart = leftEnd + 1;
	int tempStart = leftStart;
	int index = leftStart;

	while (leftStart <= leftEnd && rightStart <= rightEnd) {
		if (v[leftStart] < v[rightStart]) {
			temp[index] = v[leftStart];
			leftStart++;
		} else {
			temp[index] = v[rightStart];
			rightStart++;
		}

		index++;
	}

	while (leftStart <= leftEnd) {
		temp[index] = v[leftStart];
		index++;
		leftStart++;
	}

	while (rightStart <= rightEnd) {
		temp[index] = v[rightStart];
		index++;
		rightStart++;
	}

	while (tempStart <= rightEnd) {
		v[tempStart] = temp[tempStart];
		tempStart++;
	}
}

template <typename T>
void mergeSort(std::vector<T>& v, std::vector<T>& temp, int start, int end) {
	if (start >= end) {
		return;
	}

	int mid = (start + end) / 2;
	mergeSort(v, temp, start, mid);
	mergeSort(v, temp, mid + 1, end);

	merge(v, temp, start, mid, end);
}

template <typename T>
void mergeSort(std::vector<T>& v) {
	std::vector<T> temp;
	temp.resize(v.size());

	mergeSort(v, temp, 0, v.size() - 1);
}

const int MIN_SIZE = 10;

template <typename T>
void quickSort(std::vector<T>& v, int start, int end) {
	if (start + MIN_SIZE > end) {
		insertionSort(v, start, end);
	}

	int middle = (start + end) / 2;

	if (v[middle] < v[start]) {
		swap(v[middle], v[start]);
	}

	if (v[end] < v[start]) {
		swap(v[end], v[start]);
	}

	if(v[end] < v[middle]) {
		swap(v[end], v[middle]);
	}

	T pivot = v[middle];

	swap(v[middle], v[end - 1]);

	int i = start;
	int j = end - 1;

	while (true) {
		while (v[++i] < pivot) {}

		while (pivot < v[--j]) {}

		if (i < j) {
			swap(v[i], v[j]);
		} else {
			break;
		}
	}

	swap(v[i], v[end - 1]);

	quickSort(v, start, i - 1);
	quickSort(v, i + 1, end);
}

template <typename T>
void quickSort(std::vector<T>& v) {
	quickSort(v, 0, v.size() - 1);
}

template <typename T>
void selectionSort(std::vector<T>& v) {
	for (int i = 0; i < v.size(); i++) {
		int low = i;

		for (int j = i + 1; j < v.size(); j++) {
			if (v[j] < v[low]) {
				low = j;
			}
		}

		T temp = v[low];
		v[low] = v[i];
		v[i] = temp;
	}
}

template <typename T>
void setSort(std::vector<T>& v) {
	std::multiset<T> s;
	for (T i : v) {
		s.insert(i);
	}
	v.clear();

	for (typename std::multiset<T>::iterator it = s.begin(); it != s.end(); it++) {
		v.push_back(*it);
	}
	s.clear();
}

template <typename T>
void shellSort(std::vector<T>& v) {
	for (int gap = v.size() / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < v.size(); i++) {
			T temp = v[i];
			int j = i;

			for (; j >= gap && temp < v[j - gap]; j-= gap) {
				v[j] = v[j - gap];
			}

			v[j] = temp;
		}
	}
}

/*
 * SORTING USING COMPARATORS
 */
template <typename T, typename C>
void insertionSort(std::vector<T>& v, C comparator) {
	insertionSort(v, comparator, 0, v.size());
}

template <typename T, typename C>
void insertionSort(std::vector<T>& v, C comparator, int start, int end) {
	for (int i = start + 1; i <= end; i++) {
		T temp = v[i];
		int j = i;

		while (j > start && comparator(temp, v[j - 1])) {
			v[j] = v[j - 1];
			j--;
		}

		v[j] = temp;
	}
}

template <typename T, typename C>
void merge(std::vector<T>& v, std::vector<T>& temp, C comparator, int leftStart, int leftEnd, int rightEnd) {
	int rightStart = leftEnd + 1;
	int tempStart = leftStart;
	int index = leftStart;

	while (leftStart <= leftEnd && rightStart <= rightEnd) {
		if (comparator(v[leftStart], v[rightStart])) {
			temp[index] = v[leftStart];
			leftStart++;
		} else {
			temp[index] = v[rightStart];
			rightStart++;
		}

		index++;
	}

	while (leftStart <= leftEnd) {
		temp[index] = v[leftStart];
		index++;
		leftStart++;
	}

	while (rightStart <= rightEnd) {
		temp[index] = v[rightStart];
		index++;
		rightStart++;
	}

	while (tempStart <= rightEnd) {
		v[tempStart] = temp[tempStart];
		tempStart++;
	}
}

template <typename T, typename C>
void mergeSort(std::vector<T>& v, std::vector<T>& temp, C comparator, int start, int end) {
	if (start >= end) {
		return;
	}

	int mid = (start + end) / 2;
	mergeSort(v, temp, comparator, start, mid);
	mergeSort(v, temp, comparator, mid + 1, end);

	merge(v, temp, comparator, start, mid, end);
}

template <typename T, typename C>
void mergeSort(std::vector<T>& v, C comparator) {
	std::vector<T> temp;
	temp.resize(v.size());

	mergeSort(v, temp, comparator, 0, v.size() - 1);
}

template <typename T, typename C>
void quickSort(std::vector<T>& v, C comparator, int start, int end) {
	if (start + MIN_SIZE > end) {
		insertionSort(v, comparator, start, end);
	}

	int middle = (start + end) / 2;

	if (comparator(v[middle], v[start])) {
		swap(v[middle], v[start]);
	}

	if (comparator(v[end], v[start])) {
		swap(v[end], v[start]);
	}

	if (comparator(v[end], v[middle])) {
		swap(v[end], v[middle]);
	}

	T pivot = v[middle];

	swap(v[middle], v[end - 1]);

	int i = start;
	int j = end - 1;

	while (true) {
		while (v[++i] < pivot) {}

		while (pivot < v[--j]) {}

		if (i < j) {
			swap(v[i], v[j]);
		} else {
			break;
		}
	}

	swap(v[i], v[end - 1]);

	quickSort(v, comparator, start, i - 1);
	quickSort(v, comparator, i + 1, end);
}

template <typename T, typename C>
void quickSort(std::vector<T>& v, C comparator) {
	quickSort(v, comparator, 0, v.size() - 1);
}

template <typename T, typename C>
void selectionSort(std::vector<T>& v) {
	for (int i = 0; i < v.size(); i++) {
		int low = i;

		for (int j = i + 1; j < v.size(); j++) {
			if (v[j] < v[low]) {
				low = j;
			}
		}

		T temp = v[low];
		v[low] = v[i];
		v[i] = temp;
	}
}

template <typename T, typename C>
void shellSort(std::vector<T>& v, C comparator) {
	for (int gap = v.size() / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < v.size(); i++) {
			T temp = v[i];
			int j = i;

			for (; j >= gap && comparator(temp, v[j - gap]); j-= gap) {
				v[j] = v[j - gap];
			}

			v[j] = temp;
		}
	}
}
