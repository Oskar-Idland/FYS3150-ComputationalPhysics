#include "A.h"
#include <armadillo>
using arma::vec, arma::mat;

vec A(vec x) {
    mat A_mat (x.n_elem, x.n_elem, arma::fill::zeros);

    A_mat.diag() += 2;
    A_mat.diag(1) += -1;
    A_mat.diag(-1) += -1;

    return A_mat;
}