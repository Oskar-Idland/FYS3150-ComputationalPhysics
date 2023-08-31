.DEFAULT_GOAL := default
CC = g++
CFLAG = --std=c++17 -Wall

default: compile move link run done

	
all: compile move link run clean done

comp_main: compile_main link run

compile_main: 
	g++ $(CFLAG) -c main.cpp

compile:
	g++ $(CFLAG) -c $(wildcard src/*.cpp) 

link:
	g++ $(CFLAG) -o src/main $(wildcard objectFiles/*.o) 

run:
	./src/main

clean:
	rm -f *.o 

move_objects: move done

move:
	mv *.o objectFiles

done:
	@echo "Done!"

# Does not work as other commands can't be executed
# $(MAKECMDGOALS): 
# 	g++ $(CFLAG) -c $(MAKECMDGOALS).cpp
# 	@echo "$(MAKECMDGOALS).cpp compiled"
