template <typename T>
class PQueue{
	public:
		PQueue();
		void clear();
		T top() const;
		T pop();
		void push(T);
		bool isEmpty() const;
		void printTree() const;

	private:
		vector<T> data;
		void percolateUp(int);
		void percolateDown(int);
		void swap(int, int);
};

#include "Pqueue.cpp"
