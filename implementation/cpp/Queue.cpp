template <typename T>
Queue<T>::Queue() : data(nullptr) {
	clear();
}

template <typename T>
Queue<T>::~Queue() {
	delete [] data;
}

template <typename T>
Queue<T>::Queue(const Queue<T>& rhs) : data(nullptr) {
	*this = rhs;
}

template <typename T>
T Queue<T>::top() const {
	return data[start];
}

template <typename T>
bool Queue<T>::isEmpty() const{
	return start == end;
}

template <typename T>
T Queue<T>::pop() {
	T temp = top();
	if (isEmpty()) {
		return temp;
	}

	start++;
	if (start == capacity) {
		start = 0;
	}

	return temp;
}

template <typename T>
int Queue<T>::size() const {
	if (start <= end) {
		return end - start;
	}

	return (capacity - start) + (end);
}

template <typename T>
void Queue<T>::clear() {
	delete [] data;
	capacity = 5;
	data = new T[capacity];
	start = 0;
	end = 0;
}

template <typename T>
void Queue<T>::push(const T& item) {
	data[end++] = item;
	if (end == capacity) {
		end = 0;
	}

	if (end == start) {
		resize(capacity * 2);
	}
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& rhs) {
	if (this == &rhs) {
		return *this;
	}

	int otherSize = rhs.size() + 1;
	delete [] data;
	data = new T[otherSize];
	capacity = otherSize;
	int otherptr = rhs.start;

	do {
		push(rhs.data[otherptr++]);

		if (otherptr == rhs.capacity) {
			otherptr = 0;
		}
	} while (otherptr != rhs.end);
}

template <typename T>
void Queue<T>::resize(int newsize) {
	T* temp = new T[newsize];
	int tempptr = 0;
	int dataptr = start;

	do {
		temp[tempptr++] = data[dataptr++];
		if (dataptr == capacity) {
			dataptr = 0;
		}
	} while (dataptr != end);

	start = 0;
	end = tempptr;
	capacity = newsize;
	delete [] data;
	data = temp;
}
