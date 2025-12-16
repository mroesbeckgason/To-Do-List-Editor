//============================================================================
// Name        : p4.cpp
//
// Desc		   : main file, lets you create a to do list, add remove, check,
// uncheck tasks, and save and load lists.
//
// Author      : Mason Groesbeck
//============================================================================


#include "list.h"
#include <iostream>
#include <fstream>
#include <sstream>

int main() {
	std::cout << "              -----------TO DO LIST-----------" << std::endl;
	std::cout << "      please choose from one of the following commands" << std::endl;
	std::cout << "- add - remove - check - uncheck - save - load - quit - print -\n" << std::endl;
	bool done = false;
	bool bad_input;
	std::string line;

	TodoList list;
	TodoList saved_list;


	while (!done && std::getline(std::cin, line)) {

		std::stringstream stream(line);
		std::string command;
		stream >> command;
		bad_input = false;


		if (command == "add") {
			std::string name;
			std::string text;
			if (stream >> name) {
				std::getline(stream, text);

				if (!text.empty() && text[0] == ' ') {
					text.erase(0, 1);
				}
				list.add(name, text);
			} else {
				bad_input = true;
			}

		} else if (command == "remove") {
			std::string name;
			if (stream >> name) {
				list.remove(name);
			} else {
				bad_input = true;
			}
		} else if (command == "check") {
			std::string name;
			if (stream >> name) {
				list.check(name);
			} else {
				bad_input = true;
			}

		} else if (command == "uncheck") {
			std::string name;
			if (stream >> name) {
				list.uncheck(name);
			} else {
				bad_input = true;
			}

		} else if (command == "save") {
			saved_list = list;
			list = TodoList();

		} else if (command == "load") {
			list = saved_list;

		} else if (command == "print") {
			list.print();

		} else if (command == "quit") {
			done = true;

		} else {
			std::cout << "please enter a proper command" << std::endl;
		}

		if (bad_input) {
			std::cout << "Bad Input" << std::endl;
		}
		std::cout << std::endl;
		std::cout << "              -----------TO DO LIST-----------" << std::endl;
		std::cout << "      please choose from one of the following commands" << std::endl;
		std::cout << "- add - remove - check - uncheck - save - load - quit - print -\n" << std::endl;
		list.print();
		std::cout << std::endl;
	}
	std::cout << "goodbye" << std::endl;
	return 0;
}
