all: compile link run

compile:
  g++ --std++17 -c main.cpp

link:
  g++ --std++17 -o main.out main.o

run:
  ./main.out