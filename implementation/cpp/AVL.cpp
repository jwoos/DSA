#include <queue>

template <typename T>
AVLNode::AVLNode(const T& newdata = T(), AVLNode<T>* newparent = nullptr, AVLNode<T>* newleft = nullptr, AVLNode<T>* newright = nullptr) : data(newdata), parent(newparent), left(newleft), right(newright) {
	calculateHeight();
}

template <typename T>
AVL<T>::AVL() : root(nullptr) {}

template <typename T>
AVL<T>::~AVL() {
	clear();
}

template <typename T>
void AVL<T>::printPreOrder(AVLNode* start) {
	if (start != nullptr) {
		cout << (start -> data) << ", ";
		printPostOrder(start -> left);
		printPostOrder(start -> right);
	}
}

template <typename T>
void AVL<T>::printInOrder(AVLNode* start) {
	if (start != nullptr) {
		printPostOrder(start -> left);
		cout << (start -> data) << ", ";
		printPostOrder(start -> right);
	}
}

template <typename T>
void AVL<T>::printPostOrder(AVLNode* start) {
	if (start != nullptr) {
		printPostOrder(start -> left);
		printPostOrder(start -> right);
		cout << (start -> data) << ", ";
	}
}

template <typename T>
void AVL<T>::printLevelOrder(AVLNode* start) {
	if (start == nullptr) {
		return;
	}

	queue<AVLNode<T>*> q;
	q.push(start);

	while (!q.empty()){
		cout << q.front() -> data << ", ";

		if (q.front() -> left != nullptr) {
			q.push(q.front() -> left);
		}

		if (q.front() -> right != nullptr) {
			q.push(q.front() -> right);
		}

		q.pop();
	}
}

template <typename T>
void AVL<T>::remove(const T& data) {
	AVLNode* node = find(data);

	if (toRemove == nullptr) {
		return;
	}

	if (toRemove -> left == nullptr && toRemove -> right == nullptr) {
		if (toRemove == root) {
			root = nullptr;
		} else {
			if (toRemove == toRemove -> parent -> left) {
				toRemove -> parent -> left = nullptr;
			} else {
				toRemove -> parent -> right = nullptr;
			}
		}

		delete toRemove;
	} else if (toRemove -> left == nullptr) {
		AVLNode<T>* rightChild = toRemove -> right;

		toRemove -> data = rightChild -> data;
		toRemove -> left = rightChild -> left;
		toRemove -> right = rightChild -> right;

		if (toRemove -> left != nullptr) {
			toRemove -> left -> parent = toRemove;
		}

		if (toRemove -> right != nullptr) {
			toRemove -> right -> parent = toRemove;
		}

		delete rightChild;
	}
	else if (toRemove -> right == nullptr) {
		AVLNode<T>* leftChild = toRemove -> left;

		toRemove -> data = leftChild -> data;
		toRemove -> right = leftChild -> right;
		toRemove -> left = leftChild -> left;

		if (toRemove -> left != nullptr) {
			toRemove -> left -> parent = toRemove;
		}

		if (toRemove -> right != nullptr) {
			toRemove -> right -> parent = toRemove;
		}

		delete leftChild;
	} else {
		AVLNode<T>* temp = toRemove -> right;

		while (temp -> left != nullptr) {
			temp = temp -> left;
		}

		toRemove -> data = temp -> data;
		remove(temp);
	}
}

template <typename T>
bool AVL<T>::isEmpty() const {
	return root == nullptr;
}

template <typename T>
void AVL<T>::clear() {
	if (root == nullptr) {
		return;
	}

	queue<AVLNode<T>*> q;
	q.push(root);
	root = nullptr;

	while (!q.empty()){
		if (q.front() -> left != nullptr) {
			q.push(q.front() -> left);
		}

		if (q.front() -> right != nullptr) {
			q.push(q.front() -> right);
		}

		delete q.front();
		q.pop();
	}
}

template <typename T>
void AVL<T>::insert(const T& data) {
	if (isEmpty()) {
		root = new AVLNode<T>(data);
	} else {
		AVLNode<T>* temp = root;
		AVLNode<T>* prev = root;

		while (temp != nullptr) {
			prev = temp;
			if (temp -> data > data) {
				temp = temp -> left;
			} else {
				temp = temp -> right;
			}
		}
		if (prev -> data > data) {
			prev -> left = new AVLNode<T>(data, prev);
		} else {
			prev -> right = new AVLNode<T>(data, prev);
		}
	}
}

template <typename T>
AVLNode<T>* AVL<T>::find(const T& data) {
	AVLNode<T>* temp = root;

	while (temp != nullptr) {
		if (temp -> data == data) {
			return temp;
		} else if (temp -> data > data) {
			temp = temp -> left;
		} else {
			temp = temp -> right;
		}
	}

	return nullptr;
}

template <typename T>
int AVL<T>::getHeight(AVLNode* node) {
	return node == nullptr ? -1 : node -> height;
}
