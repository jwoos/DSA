template <class T>
class Queue{
	public:
		Queue();
		~Queue();
		Queue(const Queue<T>&);
		T top() const;
		bool isEmpty() const;
		T pop();
		int size() const;
		void clear();
		void push(const T&);
		Queue<T>& operator=(const Queue<T>&);

	private:
		T* data;
		int start;
		int end;
		int capacity;
		void resize(int);
};

#include "Queue.cpp"
