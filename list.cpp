//============================================================================
// Name        : list.cpp
//
// Desc		   : lists cpp file, has methods for TodoList class
//
// Author      : Mason Groesbeck
//============================================================================

#include "list.h"
#include <iostream>

// Default constructor
// Pre: N/A
// Post: initializes a new instance of TodoList
TodoList::TodoList() {
	head = nullptr;
	curr = head;
}

// Copy constructor
// Pre: takes another instance of TodoList
// Post: initializez a new instance of TodoList
// with the same pieces of other
TodoList::TodoList(TodoList const &other) {
	if (other.head == nullptr) {
		head = nullptr;
		curr = head;
		return;
	}
	head = new Node;
	head->name = other.head->name;
	head->text = other.head->text;
	head->checked = other.head->checked;
	head->next = nullptr;

	curr = head;
	Node* curr_other = other.head->next;

	while (curr_other != nullptr) {
		curr->next = new Node;
		curr = curr->next;

		curr->name = curr_other->name;
		curr->text = curr_other->text;
		curr->checked = curr_other->checked;
		curr->next = nullptr;

		curr_other = curr_other->next;
	}
}

// overload operator
// Pre: takes a seperate instance of TodoList
// Post: sets one instance of TodoList equal to another
void TodoList::operator=(TodoList const &other) {

	if (this == &other) {
		return;
	}

	Node* iter = head;
	while (iter != nullptr) {
		Node* temp = iter->next;
		delete iter;
		iter = temp;
	}
	head = nullptr;
	curr = nullptr;

	if (other.head == nullptr) {
		return;
	}

	head = new Node;
	head->name = other.head->name;
	head->text = other.head->text;
	head->checked = other.head->checked;
	head->next = nullptr;

	iter = other.head->next;
	curr = head;
	while (iter != nullptr) {
		curr->next = new Node;
		curr = curr->next;

		curr->name = iter->name;
		curr->text = iter->text;
		curr->checked = iter->checked;
		curr->next = nullptr;

		iter = iter->next;

	}
	curr = head;

}

// allows you to add nodes to an instance linked list
// Pre: takes string for input_name and input_text
// Post: adds a node with input_name and input_text as name and text
// to TodoList linked list
void TodoList::add(std::string input_name, std::string input_text) {
	Node* temp = new Node;
	temp->name = input_name;
	temp->text = input_text;
	temp->checked = false;
	temp->next = nullptr;

	if (head == nullptr) {
		head = temp;
		curr = head;

	} else {
		Node* iter = head;
		while (iter->next != nullptr) {
			iter = iter->next;
		}
		iter->next = temp;
	}
}

// Removes a node from TodoList linked list
// Pre: takes string input_name
// Post: removes the node with input_name as name from linked list
void TodoList::remove(std::string input_name) {

	if (head == nullptr) {
		return;
	}

	curr = head;
	Node* previous = head;

	while (curr != nullptr) {
		if (head->name == input_name) {
			Node* temp = head;
			head = head->next;
			delete temp;
		} else if (curr->name == input_name) {
			previous->next = curr->next;
			delete curr;
		}
		if (curr != head) {
			previous = previous->next;
		}
		curr = curr->next;
	}
}

// sets bool "checked" to true for a certain node
// Pre: takes string input_name
// Post: sets the node named input_name to checked
void TodoList::check(std::string input_name) {
	if (curr->name == input_name) {
		curr->checked = true;
	}
	curr = head;
	while (curr->next != nullptr) {
		curr = curr->next;
		if (curr->name == input_name) {
			curr->checked = true;
		}
	}
	curr = head;

}

// sets bool "checked" to false for a certain node
// Pre: takes string input_name
// Post: sets the node named input_name to unchecked
void TodoList::uncheck(std::string input_name) {
	curr = head;

	if (curr->name == input_name) {
		curr->checked = false;
	}
	while (curr->next != nullptr) {
		curr = curr->next;
		if (curr->name == input_name) {
			curr->checked = false;
		}
	}
	curr = head;
}

// prints entire instance of linked list
// Pre: N/A
// Post: prints entire linked list in a readable way
void TodoList::print() {
	Node* iter = head;
	while (iter != nullptr) {
		if (iter->checked) {
			std::cout << "[X] ";
		} else {
			std::cout << "[ ] ";
		}
		std::cout << iter->name << " " << iter->text << std::endl;
		iter = iter->next;
	}
}

// Deconstructor
// Pre: N/A
// Post: deallocates all memory for the certain instance
// of TodoList
TodoList::~TodoList() {
	Node* iter = head;
	while (iter != nullptr) {
		Node* next = iter->next;
		delete iter;
		iter = next;
	}


}

