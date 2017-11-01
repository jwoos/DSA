template <typename T>
Itr::Itr(Node<T>* newPtr = nullptr) : ptr(newPtr) {}

template <typename T>
bool Itr::operator==(const Itr<T>& rhs) const {
	return ptr == rhs.ptr;
}

template <typename T>
bool Itr::operator!=(const Itr<T>& rhs) const {
	return ptr != rhs.ptr;
}

template <typename T>
T Itr::operator*() const {
	return ptr -> data;
}

template <typename T>
T& Itr::operator*() {
	return ptr -> data;
}

template <typename T>
Itr<T>& Itr::operator++() {
	if (ptr -> next == nullptr) {
		return *this;
	}

	ptr = ptr -> next;
	return *this;
}

template <typename T>
Itr<T>& Itr::operator--() {
	if (ptr -> prev == nullptr) {
		return *this;
	}

	ptr = ptr -> prev;
	return *this;
}

template <typename T>
Itr<T> Itr::operator++() {
	Itr<T> temp = *this;

	if (prt -> next == nullptr) {
		return *this;
	}

	ptr = ptr -> next;
	return temp;
}

template <typename T>
Itr<T> Itr::operator--() {
	Itr<T> temp = *this;

	if (prt -> prev == nullptr) {
		return *this;
	}

	ptr = ptr -> prev;
	return temp;
}

template <typename T>
Node::Node(const T& newData = T(), Node<T>* newPrev = nullptr, Node<T>* newNext = nullptr) : data(newData), next(newNext), prev(newPrev) {}

template <typename T>
List::List() {
	numOfElements = 0;
	head = new Node<T>();
	tail = new Node<T>(T(), head);
	head -> next = tail;
	tail -> prev = head;
}

template <typename T>
List::~List() {
	clear();
	delete head;
	delete tail;
}

template <typename T>
T List<T>::remove(Itr<T> itr){
	if (itr.ptr -> next == nullptr || itr.ptr -> prev == nullptr) {
		return T();
	}

	T retval = itr.ptr -> data;
	Node<T>* temp = itr.ptr;
	numOfElements--;
	temp -> next -> prev = temp -> prev;
	temp -> prev -> next = temp -> next;

	delete temp;
	itr.ptr = tail;

	return retval;
}

template<typename T>
void List<T>::insertBefore(Itr<T> itr, const T& item){
	if (itr.ptr -> prev == nullptr) {
		return;
	}

	insertAfter(--itr, item);
}

template <typename T>
void List<T>::insertAfter(Itr<T> itr, const T& item){
	if (itr.ptr -> next == nullptr) {
		return;
	}

	numOfElements++;
	Node<T>* temp = new Node<T>(item);
	temp -> next = itr.ptr -> next;
	temp -> prev = itr.ptr;
	itr.ptr -> next = temp;
	temp -> next -> prev = temp;
	itr.ptr -> next = itr.ptr -> next -> prev = new Node<T>(item, itr.ptr, itr.ptr -> next);
}

template <typename T>
List<T>& List<T>::operator=(const List<T>& rhs){
	if (this == &rhs) {
		return *this;
	}

	clear();

	for (ListItr<T> i = rhs.head -> next; i != rhs.tail; i++) {
		push_back(*i);
	}

	return *this;
}

template <typename T>
Itr<T> List::begin() {
	return head -> next;
}

template <typename T>
Itr<T> List::end() {
	return tail;
}

template <typename T>
int List::size() {
	return numOfElements;
}

template <typename T>
bool List::isEmpty() {
	return head -> next == tail;
}

template <typename T>
void List::push_back(const T& item) {
	insertBefore(tail, item);
}

template <typename T>
void List::push_front(const T& item) {
	insertAfter(head, item);
}

template <typename T>
T List::pop_back() {
	return remove(tail -> prev);
}

template <typename T>
T List::pop_front() {
	return remove(begin());
}

template <typename T>
void List::clear() {
	while (!isEmpty()) {
		pop_front();
	}
}
