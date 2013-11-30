all: Buildings
Buildings: Date.o Building.o SearchEngine.o
	g++ -Wall -g -o Buildings Date.o Building.o SearchEngine.o
SearchEngine.o: SearchEngine.cpp
	g++ -c -Wall -g SearchEngine.cpp
Building.o: Building.cpp
	g++ -c -Wall -g Building.cpp
Date.o: Date.cpp
	g++ -c -Wall -g Date.cpp
