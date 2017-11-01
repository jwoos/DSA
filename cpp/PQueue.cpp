template <typename T>
PQueue::PQueue() {
	clear();
}

template <typename T>
void PQueue::clear() {
	data.resize(1);
}

template <typename T>
void PQueue::swap(int posA, int posB) {
	T temp = data[posA];
	data[posA] = data[posB];
	data[posB] = temp;
}

template <typename T>
void PQueue<T>::push(T newVal) {
	data.push_back(newVal);
	percolateUp(data.size() - 1);
}

template <typename T>
T PQueue<T>::pop() {
	T retval = top();
	if (!isEmpty()) {
		data[1] = data[data.size() - 1];
		data.pop_back();
		percolateDown(1);
	}
	return retval;
}

template <typename T>
void PQueue<T>::percolateUp(int pos) {
	if (pos == 1) {
		return;
	}

	if (data[pos] < data[pos / 2]) {
		swap(pos, pos / 2);
		percolateUp(pos / 2);
	}
}

template <typename T>
void PQueue<T>::percolateDown(int pos) {
	if (pos == data.size()) {
		return;
	}

	if ((pos * 2) >= data.size()) {
		return;
	}

	if ((pos * 2) == (data.size() - 1)) {
		if (data[pos] >= data[pos * 2]) {
			swap(pos, pos * 2);
		}
		return;
	}

	if (data[pos * 2] < data[pos] || data[pos * 2 + 1] < data[pos]) {
		if (data[pos * 2] <= data[pos * 2 + 1]) {
			swap(pos, pos * 2);
			percolateDown(pos * 2);
		} else {
			swap(pos, pos * 2 + 1);
			percolateDown(pos * 2 + 1);
		}
	}
}

template <typename T>
bool PQueue::isEmpty() {
	return data.size() == 1;
}

template <typename T>
void PQueue::printTree() {
	for (T i : data) {
		cout << i << ',';
	}
	cout << endl;
}

template <typename T>
T PQueue::top() {
	return data[1];
}

#include <vector>
