template <class T>
class AVLNode{
	public:
		AVLNode(const T&, AVLNode<T>*, AVLNode<T>*, AVLNode<T>*);
		void calculateHeight();

	private:
		int height;
		T data;
		AVLNode<T> *parent;
		AVLNode<T> *left;
		AVLNode<T> *right;

	friend class AVL<T>;
};

template <class T>
class AVL{
	public:
		AVL();
		virtual ~AVL();
		void printPreOrder();
		void printInOrder();
		void printPostOrder();
		void printLevelOrder();
		void remove(const T&);
		bool isEmpty() const;
		void clear();
		void insert(const T&);
		AVLNode<T>* find(const T&);

	private:
		AVLNode<T>* root;
		void printPreOrder(AVLNode<T>*);
		void printInOrder(AVLNode<T>*);
		void printPostOrder(AVLNode<T>*);
		void printLevelOrder(AVLNode<T>*);
		void remove(AVLNode<T>*);
		AVLNode<T>* recursiveCopy(AVLNode<T>*);
		int getHeight(AVLNode<T>*);
		void doRotation(AVLNode<T>*);
		void singleCCR(AVLNode<T>*);
		void singleCR(AVLNode<T>*);
		void doubleCCR(AVLNode<T>*);
		void doubleCR(AVLNode<T>*);
};

#include "AVL.cpp"
