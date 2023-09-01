# FYS3150 - Computational Physics: Project 1

## Table of Contents
- [Build and Run](#build-and-run)
- [Project Structure](#project-structure)

## Build and Run
- To build the project, run `make` in the root folder
- Alternativly run the following commands

1. Compile
```bash
g++ --std=c++17 -Wall -m64 -c src/f.cpp src/find_v.cpp src/main.cpp src/u.cpp src/write_to_file.cpp
```
2. Move object files to objectFiles folder
```bash
mv *.o objectFiles
```
3. Link object files and create executable
```bash
g++ --std=c++17 -Wall -m64 -o src/main objectFiles/f.o objectFiles/find_v.o objectFiles/main.o objectFiles/u.o objectFiles/write_to_file.o
```	
- To run the project, run `./src/main` in the root folder

## Project Structure
The code is divided into multiple folders
- data: All data and graphs produced
- include: Header files (.h)
- objectFiles: Object files (.o)
- scripts: Scripts to plot data (python)
- src: Source files (.cpp)
- tex: LaTeX files (.tex)

makefile: Makefile to compile the code, placed in the root folder