# FYS3150 - Computational Physics: Project 1

## Table of Contents
- [Downloading the Project](#downloading-the-project)
- [Build and Run](#build-and-run)
- [Project Structure](#project-structure)
- [Authors](#authors)


## Downloading the Project
To download the project, run the following command in the terminal
```bash
git clone https://github.com/Oskar-Idland/FYS3150-ComputationalPhysics.git
```


## Build and Run
### Building with make
To build the project, run `make` in the Project 1 root folder
```bash	
cd Project1
```

```bash
make
```

### Building Without make in the Terminal
1. Compile
```bash
g++ --std=c++17 -Wall -O3 -c src/decimalSeparator.cpp src/find_v_general.cpp src/find_v_matrix.cpp src/g_func.cpp src/main.cpp src/u_func.cpp src/write_to_file.cpp
```
2. Move object files to objectFiles folder
```bash
mv *.o objectFiles
```
3. Link object files and create executable
```bash
g++ --std=c++17 -Wall -O3 -o src/main objectFiles/decimalSeparator.o objectFiles/find_v_general.o objectFiles/find_v_matrix.o objectFiles/find_v_special.o objectFiles/g_func.o objectFiles/main.o objectFiles/u_func.o objectFiles/write_to_file.o
```	
4. Run executable
```bash
./src/main
```

## Project Structure
- This project was created to solve the problems found in [Project 1](https://anderkve.github.io/FYS3150/book/projects/project1.html). 
- Every problem is solved in `main.cpp`, but the code is divided into multiple files to make it more readable. The code is divided into the following files and folders:
    - data: All data and graphs produced
    - include: Header files (.h)
    - objectFiles: Object files (.o)
    - scripts: Scripts to plot data (python)
    - src: Source files (.cpp)
    - tex: LaTeX files (.tex)
    - makefile: Makefile to compile the code, placed in the root folder


## Authors
- Oskar Idland [@Oskar-Idland](https://github.com/Oskar-Idland)
- Håvard Skåli [@paljettrosa](https://github.com/paljettrosa)
- Hishem [@hishemok](https://github.com/hishemok)
- Andrew [@ASYquan](https://github.com/ASYquan)