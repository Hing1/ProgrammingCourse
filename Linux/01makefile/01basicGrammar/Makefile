CC := g++
FLAGS := -std=c++11 -w

main : support1.o main.o
	$(CC) $(FLAGS) main.o support1.o -o $@

support1.o : support1.cpp support1.hpp
	$(CC) $(FLAGS) -c support1.cpp

main.o : main.cpp
	$(CC) $(FLAGS) -c main.cpp

clean :
	@rm -r *.o
	@rm -f *.gch
	@rm -f main

