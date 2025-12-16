p4 : list.o  p4.cpp
	g++ p4.cpp list.o  -std=c++11 -Wall -Werror -g -o p4

list.o : list.h list.cpp
	g++ list.cpp                -std=c++11 -Wall -Werror -g -c
