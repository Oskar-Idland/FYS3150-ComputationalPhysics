#include <armadillo>
#include "../include/find_v.h"
using arma::vec, arma::mat;

vec find_v(vec g, mat A) {
  // Defining the augmented matrix Ag = [A | g]
  mat Ag (g.n_elem, g.n_elem + 1, arma::fill::zeros);
  Ag.submat(0, 0, Ag.n_rows - 1, Ag.n_cols - 2) = A;
  Ag.col(Ag.n_cols - 1) = g;
  
  // Implementation of the algorithm from Problem 6
  size_t n {Ag.n_rows};
  for (size_t i {}; i < n-1; ++i) { // Had to use n-1 instead of n-2 to go through all rows
    Ag.row(i+1)  -= Ag.row(i) * (Ag.row(i+1)[i] / Ag.row(i)[i]);
  }
  for (size_t i {n}; i-- > 1;) { // Had to use n instead of n-1 to go through all rows
    Ag.row(i) /= Ag.row(i)[i];
    Ag.row(i-1) -= Ag.row(i-1)[i] * Ag.row(i); 
  }
  Ag.row(0) /= Ag.row(0)[0];

  // Extracting the solution v from the augmented matrix Ag and setting the boundary conditions
  vec v = Ag.col(Ag.n_cols-1);
  v[0] = 0;
  v[v.n_elem-1] = 0;

  return v;
}