//============================================================================
// Name        : list.h
//
// Desc		   : list h file, defining TodoList class
//
// Author      : Mason Groesbeck
//============================================================================

#include <iostream>



class TodoList {
	private:

	struct Node {
		std::string name;
		std::string text;
		bool checked;
		Node* next;
	};

	Node* head;
	Node* curr;


	public:

	TodoList();
	TodoList(TodoList const &other);

	void operator=(TodoList const &other);
	void add(std::string input_name, std::string input_text);
	void remove(std::string input_name);
	void check(std::string input_name);
	void uncheck(std::string input_name);
//	void save();
//	void load();
	void print();

	~TodoList();
};
