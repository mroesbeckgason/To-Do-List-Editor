To-Do List Editor

A command-line to-do list editor written in C++. The program allows users to manage a list of tasks with names, descriptions, and checked/unchecked states. Tasks are always kept in alphabetical order by name.

Features

Maintain an active to-do list and an in-memory saved list

Add, remove, check, and uncheck tasks

Overwrite or update existing tasks by name

Save and load list states during program execution

Alphabetical ordering enforced at all times

Fully dynamic memory management using a linked list

Commands

add <name> <text...> — Add a new task or update an existing one

remove <name> — Remove a task by name

check <name> — Mark a task as checked

uncheck <name> — Mark a task as unchecked

save — Save the current active list in memory

load — Load the saved list into the active list

quit — Exit the program

Implementation Details

Core logic is encapsulated in a TodoList class

Tasks are stored as a dynamically allocated linked list

Implements the Rule of Three:

Copy constructor

Assignment operator

Destructor

No global state; all data is managed safely and privately

Files

list.h — Class declarations

list.cpp — Class definitions

p4.cpp — Program entry point and command handling

Memory Safety

No memory leaks or invalid accesses

Fully compatible with valgrind

All dynamic memory is properly freed before program exit

Build & Run
make
./p4
