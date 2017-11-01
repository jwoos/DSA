#include <queue>

template <typename T>
BST<T>::BST() : root(nullptr) {}

template <typename T>
BST<T>::~BST() {
	clear();
}

template <typename T>
void BST<T>::printPreOrder(BSTNode* start) {
	if (start != nullptr) {
		cout << (start -> data) << ", ";
		printPostOrder(start -> left);
		printPostOrder(start -> right);
	}
}

template <typename T>
void BST<T>::printInOrder(BSTNode* start) {
	if (start != nullptr) {
		printPostOrder(start -> left);
		cout << (start -> data) << ", ";
		printPostOrder(start -> right);
	}
}

template <typename T>
void BST<T>::printPostOrder(BSTNode* start) {
	if (start != nullptr) {
		printPostOrder(start -> left);
		printPostOrder(start -> right);
		cout << (start -> data) << ", ";
	}
}

template <typename T>
void BST<T>::printLevelOrder(BSTNode* start) {
	if (start == nullptr) {
		return;
	}

	queue<BSTNode<T>*> q;
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
void BST<T>::remove(const T& data) {
	BSTNode* node = find(data);

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
		BSTNode<T>* rightChild = toRemove -> right;

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
		BSTNode<T>* leftChild = toRemove -> left;

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
		BSTNode<T>* temp = toRemove -> right;

		while (temp -> left != nullptr) {
			temp = temp -> left;
		}

		toRemove -> data = temp -> data;
		remove(temp);
	}
}

template <typename T>
bool BST<T>::isEmpty() const {
	return root == nullptr;
}

template <typename T>
void BST<T>::clear() {
	if (root == nullptr) {
		return;
	}

	queue<BSTNode<T>*> q;
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
void BST<T>::insert(const T& data) {
	if (isEmpty()) {
		root = new BSTNode<T>(data);
	} else {
		BSTNode<T>* temp = root;
		BSTNode<T>* prev = root;

		while (temp != nullptr) {
			prev = temp;
			if (temp -> data > data) {
				temp = temp -> left;
			} else {
				temp = temp -> right;
			}
		}
		if (prev -> data > data) {
			prev -> left = new BSTNode<T>(data, prev);
		} else {
			prev -> right = new BSTNode<T>(data, prev);
		}
	}
}

template <typename T>
BSTNode<T>* BST<T>::find(const T& data) {
	BSTNode<T>* temp = root;

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
