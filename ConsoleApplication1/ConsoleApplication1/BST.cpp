//default ctor
template<typename ItemType>
BST<ItemType>::BST() : myRoot(nullptr) {}

//copy ctor
template<typename ItemType>
BST<ItemType>::BST(const BST<ItemType>& rhs) : myRoot(nullptr) {
	if (rhs.myRoot != nullptr) {
		myRoot = new BinNode<ItemType>(*rhs.myRoot);
	}
}

//dtor
template<typename ItemType>
BST<ItemType>::~BST() {
	delete myRoot;	//does nothing if myRoot is nullptr
	myRoot = nullptr;
}

//assignment operator
template<typename ItemType>
const BST<ItemType>& BST<ItemType>::operator=(const BST<ItemType>& rhs) {
	if (this == &rhs) {
		return *this;
	}
	BST<ItemType> tmp(rhs);
	std::swap(this.myRoot, tmp.myRoot);
	return *this;
}

template<typename ItemType>
bool BST<ItemType>::isEmpty() const {
	return myRoot == nullptr;
}

template<typename ItemType>
void BST<ItemType>::insert(const ItemType& data) {
	if (isEmpty()) {
		myRoot = new BinNode<ItemType>(data);	//alt ctor
	}
	myRoot->insert(data);
}

template<typename ItemType>
void BST<ItemType>::remove(const ItemType& data) {
	if (isEmpty()) {
		return;
	}
	myRoot->remove(data);
}

template<typename ItemType>
bool BST<ItemType>::search(const ItemType& data) const {
	if (isEmpty()) {
		return false;
	}
	return myRoot->search(data);
}

template<typename ItemType>
void BST<ItemType>::print() const {
	if (!isEmpty()) {
		myRoot->print();
	}
}