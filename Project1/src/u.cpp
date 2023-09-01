<<<<<<<< HEAD:Project1/src/u.cpp
#include "../include/u.h"
========
#include "../include/u_func.h"
>>>>>>>> main:Project1/src/u_func.cpp
#include <cmath>
#include <armadillo>

arma::vec u_func (arma::vec x){
    return 1 - (1-exp(-10))*x - exp(-10*x);
}