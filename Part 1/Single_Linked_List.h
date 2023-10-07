#ifndef SINGLE_LINKED_LIST_H_
#define SINGLE_LINKED_LIST_H_

template<typename Item_Type>
class Single_Linked_List {
private:
	#include "Node.h"
public:
	/*Pushes a new node to the front of the list.
	@param item Item to put in new node*/
	void push_front(const Item_Type& item);

	/*Pushes a new node to the front of the list.
	@param item Item to put in new node*/
	void push_back(const Item_Type& item);

	/*Removes the node at the front  of the list.*/
	void pop_front();

	/*Removes the node at the back  of the list.*/
	void pop_back();

	/*Gets the node at the front of the list.
	@return The node at the front of the list*/
	Item_Type front();

	/*Gets the node at the back of the list.
	@return The node at the front of the list*/
	Item_Type back();

	/*Inserts a new node at a given index position, or at the end of the list if the given
	index in not within the list.
	@param index Index to insert node at
	@param item Item to put in new node*/
	void insert(size_t index, const Item_Type& item);

	/*Removes the node at given position index.
	@param index Index to remove node at
	@return Returns true is successful, returns false if index is outside of list*/
	bool remove(size_t index);

	/*Gets position of a given item being searched for.
	@param item Item to search for
	@return Returns the position of the first occurrence of item if it is
	found, returns the size of the list if it is not found*/
	size_t find(const Item_Type& item);

	/*Check if list is empty (has no nodes).
	@return True if empty, false if not empty*/
	bool empty();

	/*Prints list to terminal.*/
	void print_list();
	
	int get_size() {
		return num_items;
	}

	/*Constructor*/
	Single_Linked_List();

private:
	Node* head;
	Node* tail;
	Node* iterator;
	int num_items;
};
#endif