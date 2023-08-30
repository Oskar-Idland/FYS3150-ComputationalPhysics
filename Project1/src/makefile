.DEFAULT_GOAL := default

default: compile link run done
	
all: compile link run clean done

comp_main: compile_main link run

compile_main: 
	g++ --std=c++17 -c main.cpp

compile:
	g++ --std=c++17 -c $(wildcard *.cpp) 

link:
	g++ --std=c++17 -o main $(wildcard *.o)

run:
	./main

clean:
	rm -f *.o 

done:
	@echo "Done!"

$(MAKECMDGOALS):
	g++ --std=c++17 -c $(MAKECMDGOALS).cpp
	@echo "$(MAKECMDGOALS).cpp compiled"