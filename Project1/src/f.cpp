#include "../include/f.h"
#include <cmath>
#include <armadillo>

arma::vec f(arma::vec x) {
    return 100 * exp(-10 * x);
}