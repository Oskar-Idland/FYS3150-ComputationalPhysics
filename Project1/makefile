.DEFAULT_GOAL := default
CC = g++
CFLAG = --std=c++17 -Wall -O3

default: compile move link run done

	
all: compile move link run clean done

build_main: compile_main move_main link run

compile_main: 
	g++ $(CFLAG) -c src/main.cpp

compile:
	g++ $(CFLAG) -c $(wildcard src/*.cpp)

link:
	g++ $(CFLAG) -o src/main $(wildcard objectFiles/*.o)

run:
	./src/main

clean:
	rm -f *.o 

move_main:
	mv main.o objectFiles

move:
	mv *.o objectFiles

done:
	@echo "Done!"

# Create a new project with all the necessary folders and files
create_project: make_dir make_files

make_dir:
	mkdir -p data include objectFiles scripts src tex

make_files:
	touch README.md main.cpp  

# Does not work as other commands can't be executed
# $(MAKECMDGOALS): 
# 	g++ $(CFLAG) -c $(MAKECMDGOALS).cpp
# 	@echo "$(MAKECMDGOALS).cpp compiled"
