all: Bank.exe
Bank.exe: Main.o Bank.o Account.o
	g++ -Wall -g -o Bank.exe Main.o Bank.o Account.o
Main.o: Main.cpp
	g++ -c -Wall -g Main.cpp
Bank.o: Bank.cpp
	g++ -c -Wall -g Bank.cpp
Account.o: Account.cpp
	g++ -c -Wall -g Account.cpp