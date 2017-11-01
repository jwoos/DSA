template <typename T>
void Stack<T>::push(const T& item) {
	data.push_front(item);
}

template <typename T>
T Stack<T>::pop() {
	T retval = top();
	data.pop_front();
	return retval;
}

template <typename T>
T Stack<T>::top() const{
	return *data.begin();
}

template <typename T>
bool Stack<T>::isEmpty() const {
	return data.size() == 0;
}

template <typename T>
int Stack<T>::size() const {
	return data.size();
}

template <typename T>
void Stack<T>::clear() {
	data.clear();
}

