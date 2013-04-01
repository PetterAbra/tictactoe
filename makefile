all: classes 
	g++ TicTac.cpp class*.o -o TicTac

classes:
	g++ -c class*.cpp