all: Main.exe
Main.exe: MyStack.o MyQueue.o Main.o
	g++ -Wall -g -o Main.exe MyStack.o MyQueue.o Main.o
Main.o: Main.cpp
	g++ -c -Wall -g Main.cpp
MyStack.o: MyStack.cpp
	g++ -c -Wall -g MyStack.cpp
MyQueue.o: MyQueue.cpp
	g++ -c -Wall -g MyQueue.cpp
