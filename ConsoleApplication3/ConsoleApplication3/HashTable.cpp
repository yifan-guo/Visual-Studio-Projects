
template<typename ItemType>
HashTable<ItemType>::HashTable(const int& size) : myHead(new ItemType*[size])
{
	/*for (size_t i = 0; i < size; i++) {
		myHead[i] = nullptr;
	}*/
}

//template<typename ItemType>
//HashTable<ItemType>::HashTable(const HashTable<ItemType>& rhs) {
//
//}
//
//template<typename ItemType>
//const HashTable& HashTable<ItemType>::operator=(const HashTable<ItemType>& rhs) {
//
//}
//
//template<typename ItemType>
//HashTable<ItemType>::~HashTable() {
//
//}
//
//template<typename ItemType>
//void HashTable<ItemType>::insert(const ItemType<ItemType>& item) {
//
//}
//
//template<typename ItemType>
//bool HashTable<ItemType>::search(const ItemType<ItemType>& item) const {
//
//}
//
//template<typename ItemType>
//void HashTable<ItemType>::remove(const ItemType<ItemType>& item) {
//
//}
//
//template<typename ItemType>
//int HashTable<ItemType>::hash(const int& x) {
//
//}


