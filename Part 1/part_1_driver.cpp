#include <iostream>
#include "Single_Linked_List.h"
#include "Single_Linked_List.cpp"

using namespace std;

/*Prompts user to repeat the previous test or not*/
void repeat_confirmation(char& choice) {
	cout << "\nWould you like to repeat the last test? (y/n)\n";
	char input = 'n';
	cin >> input;
	choice = input;
}

int main() {
	Single_Linked_List<string> the_list;
	string input;
	int int_input;
	char repeat_choice;

	/*push_front test*/
	do {
		cout << "push_front test: Please enter a string to push to the front of the list.\nString: ";
		cin >> input;
		the_list.push_front(input);
		cout << "\nNew list is:\n";
		the_list.print_list();
		cout << "\n";
		repeat_confirmation(repeat_choice);
	} while (repeat_choice == 'y');

	/*push_back test*/
	do {
		cout << "\npush_back test: Please enter a string to push to the back of the list.\nString: ";
		cin >> input;
		the_list.push_back(input);
		cout << "\nNew list is:\n";
		the_list.print_list();
		cout << "\n";
		repeat_confirmation(repeat_choice);
	} while (repeat_choice == 'y');

	/*pop_front test*/
	do {
		cout << "\npop_front test: Front of list will be popped.\n";
		the_list.pop_front();
		cout << "\nNew list is:\n";
		the_list.print_list();
		cout << "\n";
		repeat_confirmation(repeat_choice);
	} while (repeat_choice == 'y');

	/*pop_back test*/
	do {
		cout << "\npop_back test: Back of list will be popped.\n";
		the_list.pop_back();
		cout << "\nNew list is:\n";
		the_list.print_list();
		cout << "\n";
		repeat_confirmation(repeat_choice);
	} while (repeat_choice == 'y');

	/*front and back test*/
	cout << "\nfront and back test:\nFront: " << the_list.front() << "\nBack: " << the_list.back();
	cout << "\n";

	/*empty test*/
	cout << "\nempty test:\nList is empty: " << the_list.empty() << "\n";

	/*insert test*/
	do {
		cout << "\ninsert test: Enter an index and an item to insert.\nIndex: ";
		cin >> int_input;
		cout << "\nString: ";
		cin >> input;
		the_list.insert(int_input, input);
		cout << "\nNew list is:\n";
		the_list.print_list();
		cout << "\n";
		repeat_confirmation(repeat_choice);
	} while (repeat_choice == 'y');

	/*remove test*/
	do {
		cout << "remove test: Please enter a position index to remove from the list.\nIndex: ";
		cin >> int_input;
		the_list.remove(int_input);
		cout << "\nNew list is:\n";
		the_list.print_list();
		cout << "\n";
		repeat_confirmation(repeat_choice);
	} while (repeat_choice == 'y');

	/*find test*/
	do {
		cout << "\nfind test: Please enter a string to find the index of in the list.\nString: ";
		cin >> input;
		if (the_list.find(input) == the_list.get_size())
			cout << "Item was not found in any of the " << the_list.get_size() <<" list nodes.\n";
		else
			cout << "Item was found at index " << the_list.find(input) << ".\n";
		repeat_confirmation(repeat_choice);
	} while (repeat_choice == 'y');
}
