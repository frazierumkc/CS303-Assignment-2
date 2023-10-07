#include <stdexcept>
#include <iostream>
#include "Single_Linked_List.h"

/*Pushes a new node to the front of the list.
@param item Item to put in new node*/
template<typename Item_Type>
void Single_Linked_List<Item_Type>::push_front(const Item_Type& item) {
	head = new Node(item, head);
	if (tail == NULL)
		tail = head;
	num_items++;
}

/*Pushes a new node to the front of the list.
@param item Item to put in new node*/
template<typename Item_Type>
void Single_Linked_List<Item_Type>::push_back(const Item_Type& item) {
	if (tail != NULL) {
		tail->next = new Node(item, NULL);
		tail = tail->next;
		num_items++;
	}
	else
		push_front(item);
}

/*Removes the node at the front  of the list.*/
template<typename Item_Type>
void Single_Linked_List<Item_Type>::pop_front() {
	if (head == NULL)
		throw std::invalid_argument("Attempt to call pop_front() on an empty list");
	Node* removed_node = head;
	head = head->next;
	delete removed_node;
	if (head == NULL)
		tail = NULL;
	num_items--;
}

/*Removes the node at the back  of the list.*/
template<typename Item_Type>
void Single_Linked_List<Item_Type>::pop_back() {
	if (head == NULL)
		throw std::invalid_argument("Attempt to call pop_back() on an empty list");
	Node* removed_node = tail;
	iterator = head;
	if (num_items > 2) {
		for (int i = 0; i < (num_items - 2); i++)
			iterator = iterator->next;
		tail = iterator;
	}
	else if (num_items == 2)
		tail = head;
	else {
		tail = NULL;
		head = NULL;
	}
	delete removed_node;
	num_items--;
}

/*Gets the node at the front of the list.
@return The node at the front of the list*/
template<typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::front() {
	if (empty()) {
		std::cout << "Attempt to call front() on an empty list, aborting...";
		abort();
	}
	return head->data;
}

/*Gets the node at the back of the list.
@return The node at the front of the list*/
template<typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::back() {
	if (empty()) {
		std::cout << "Attempt to call back() on an empty list, aborting...";
		abort();
	}
	return tail->data;
}

/*Inserts a new node at a given index position, or at the end of the list if the given
index in not within the list.
@param index Index to insert node at
@param item Item to put in new node*/
template<typename Item_Type>
void Single_Linked_List<Item_Type>::insert(size_t index, const Item_Type& item) {
	if (static_cast<int>(index) > (num_items - 1) || static_cast<int>(index) < 0)
		push_back(item);
	else {
		iterator = head;
		for (int i = 0; i < index - 1; i++)
			iterator = iterator->next;
		iterator->next = new Node(item, iterator->next);
	}
	num_items++;
}

/*Removes the node at given position index.
@param index Index to remove node at
@return Returns true is successful, returns false if index is outside of list*/
template<typename Item_Type>
bool Single_Linked_List<Item_Type>::remove(size_t index) {
	if (index > num_items - 1 || index < 0)
		return false;
	else {
		iterator = head;
		for (int i = 0; i < index - 1; i++)
			iterator = iterator->next;
		Node* removed_node = iterator->next;
		iterator->next = iterator->next->next;
		delete removed_node;
		num_items--;
		return true;
	}
}

/*Gets position of a given item being searched for.
@param item Item to search for
@return Returns the position of the first occurrence of item if it is
found, returns the size of the list if it is not found*/
template<typename Item_Type>
size_t Single_Linked_List<Item_Type>::find(const Item_Type& item) {
	iterator = head;
	for (int i = 0; i < num_items; i++) {
		if (iterator->data == item)
			return i;
		iterator = iterator->next;
	}
	return num_items;
}

/*Check if list is empty (has no nodes).
@return True if empty, false if not empty*/
template<typename Item_Type>
bool Single_Linked_List<Item_Type>::empty() {
	return num_items == 0;
}

/*Prints list to terminal.*/
template<typename Item_Type>
void Single_Linked_List<Item_Type>::print_list() {
	iterator = head;
	for (int i = 0; i < num_items; i++) {
		std::cout << iterator->data << " ";
		iterator = iterator->next;
	}
}

/*Constructor*/
template<typename Item_Type>
Single_Linked_List<Item_Type>::Single_Linked_List() {
	head = NULL;
	tail = NULL;
	iterator = NULL;
	num_items = 0;
}