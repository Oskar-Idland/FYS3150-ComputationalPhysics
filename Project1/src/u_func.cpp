#include "../include/u_func.h"
#include <cmath>
#include <armadillo>

arma::vec u_func (arma::vec x){
    return 1 - (1-exp(-10))*x - exp(-10*x);
}