#include "../include/u.h"
#include <cmath>
#include <armadillo>

arma::vec u (arma::vec x){
    return 1 - (1-exp(-10))*x - exp(-10*x);
}