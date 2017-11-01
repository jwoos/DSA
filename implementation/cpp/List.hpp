template <typename T>
class Itr{
	public:
		Itr(Node<T>*);
		bool operator==(const Itr<T>&) const;
		bool operator!=(const Itr<T>&) const;
		T operator*() const;
		T& operator*();
		Itr<T>& operator++();
		Itr<T>& operator--();
		Itr<T> operator--(int);
		Itr<T> operator++(int);
		friend class List <T> ;

	private:
		Node<T>* ptr;
};

template <typename T>
class Node{
	public:
		Node(const T&, Node<T>*, Node<T>*);
		friend class  <T> ;
		friend class Itr<T > ;

	private:
		T data;
		Node<T> *next;
		Node<T> *prev;
};

template <typename T>
class List {
	public:
		List();
		virtual ~List();
		Itr<T> begin();
		Itr<T> end();
		int size() const;
		bool isEmpty() const;
		void insertAfter(Itr<T>, const T&);
		void insertBefore(Itr<T>, const T&);
		T remove(Itr<T>);
		void push_back(const T&);
		void push_front(const T&);
		T pop_back();
		T pop_front();
		void clear();

	private:
		Node<T>* head;
		Node<T>* tail;
		int numOfElements;
};

#include "List.cpp"
