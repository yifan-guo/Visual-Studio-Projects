
//alt ctor
template<typename ItemType>
BinNode<ItemType>::BinNode(const ItemType& data) : item(data), left(nullptr), right(nullptr) {}

//copy ctor
template<typename ItemType>
BinNode<ItemType>::BinNode(const BinNode<ItemType>& rhs) : item(rhs.item), left(nullptr), right(nullptr) {
	if (rhs.left != nullptr) {
		left = new BinNode<ItemType> (*rhs.left);
	}
	if (rhs.right != nullptr) {
		right = new BinNode<ItemType> (*rhs.right);
	}
}

//assignment operator
template<typename ItemType>
const BinNode<ItemType>& BinNode<ItemType>::operator=(const BinNode<ItemType>& rhs) {
	if (this == &rhs) {
		return *this;
	}
	BinNode<ItemType> tmp(rhs);
	std::swap(this.item, tmp.item);
	std::swap(this.left, tmp.left);
	std::swap(this.right, tmp.right);
	return *this;
}

//dtor
template<typename ItemType>
BinNode<ItemType>::~BinNode() {
	delete this->left;
	this->left = nullptr;
	delete this->right;
	this->right = nullptr;
}

template<typename ItemType>
bool BinNode<ItemType>::search(const ItemType& data) const {
	if (data == item) {
		return true;
	}
	if (data < item && this->left != nullptr) {
		return left->search(data);
	}
	else if (data > item && this->right != nullptr) {
		return right->search(data);
	}
	return false;
}

template<typename ItemType>
void BinNode<ItemType>::print() const {
	if (left != nullptr) {
		left->print();
	}
	cout << item << endl;
	if (right != nullptr) {
		right->print();
	}
}

//pre: BinNode exists
template<typename ItemType> 
void BinNode<ItemType>::insert(const ItemType& data) {
	if (data == item) {
		return;
	}
	if (data < item) {
		if (left == nullptr) {
			left = new BinNode<ItemType>(data);
		}
		else {
			left->insert(data);
		}
	}
	else {
		if (right == nullptr) {
			right = new BinNode<ItemType>(data);
		}
		else {
			right->insert(data);
		}
	}
}

template<typename ItemType>
BinNode<ItemType>* BinNode<ItemType>::remove(const ItemType& data) {
	BinNodePtr cur = this;
	BinNodePtr prev = nullptr;
	while (cur->item != data) {	//searching
		prev = cur;
		if (data < cur->item) {
			cur = cur->left;
		}
		else if (data > cur->item) {
			cur = cur->right;
		}
	}
	if (cur->left == nullptr && cur->right == nullptr)	{ //is leaf node
		if (prev == nullptr) {	//does not have parent
			myRoot = nullptr;
			delete cur;
		}
		else {		//has parent
			if (prev->left == cur) {
				delete prev->left;
				prev->left = nullptr;
			}
			else {
				delete prev->right;
				prev->right = nullptr;
			}
		}
		cur = nullptr;
	}
	else if (cur->left != nullptr && cur->right != nullptr) {	//has two children
		BinNodePtr tmp = cur->findSuccessor();
		std::swap(cur->item, tmp->item);
		remove(tmp->item);
	}
	else {		//has one child
		if (cur->hasleftChild) {
			if (prev == nullptr) {	//does not have parent
				myRoot = cur->left;
				delete cur;
			}
			else {					//has parent
				if (prev->left == cur) {
					prev->left = cur->left;
				}
				else {
					prev->right = cur->left;
				}
				delete cur;
			}
		}
		else if (cur->hasrightChild) {
			if (prev == nullptr) {	//does not have parent
				myRoot = cur->right;
				delete cur;
			}
			else {					//has parent
				if (prev->left == cur) {
					prev->left = cur->right; 
				}
				else {
					prev->right = cur->right;
				}
				delete cur;
			}
		}
	}
}

template<typename ItemType>
BinNode<ItemType>* BinNode<ItemType>::findSuccessor() {

}
