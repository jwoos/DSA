template <typename T>
class BSTNode {
	public:
		BSTNode();

	private:
		BSTNode<T>* parent;
		BSTNode<T>* right;
		BSTNode<T>* left;
		T data;
};

template <typename T>
class BST {
	public:
		BST();
		virtual ~BST();
		BST(const BST<T>&);
		static void printPreOrder(BSTNode*);
		static void printInOrder(BSTNode*);
		static void printPostOrder(BSTNode*);
		static void printLevelOrder(BSTNode*);
		static BSTNode<T>* recursiveCopy(BSTNode<T>*);
		void remove(const T&);
		bool isEmpty() const;
		BST<T>& operator=(const BST<T>&);
		void clear();
		void insert(const T&);
		BSTNode<T>* find(const T&);

	private:
		BSTNode<T> root;
};

#include "BST.cpp"
