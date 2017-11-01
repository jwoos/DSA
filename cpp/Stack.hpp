#include <list>

template <typename T>
class Stack {
	public:
		void push(const T&);
		T pop();
		T top() const;
		bool isEmpty() const;
		int size() const;
		void clear();

	private:
		std::list<T> data;
};

#include "Stack.cpp"
