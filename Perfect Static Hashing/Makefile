CXX = g++
CXXFLAGS = -Wall -Wextra -g

SP_Hashing: main.o hashtable.o
	$(CXX) $(CXXFLAGS) -o SP_Hashing main.o hashtable.o -ldl

main.o: Hashtable.h

hashtable.o: Hashtable.h

