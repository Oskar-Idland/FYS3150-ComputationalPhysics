#include <iostream>
#include <cmath>
#include <iomanip>
#include <armadillo>
#include "../include/write_to_file.h"
#include "../include/u.h"
#include "../include/f.h"

using namespace std;
using arma::vec, arma::linspace, arma::mat;

int main()
{ 
  //------Problem 2------
  vec x {arma::linspace<vec>(0.0, 1.0, 4)};
  vec v {u(x)};
  // write_to_file(x, v, "x_u.txt");

  //------Problem 7-------
  // Defining the step size d^2x/dx^2 and the vector g
  double ddx2 {std::pow(x.at(1) - x.at(0), 2)};
  vec g {- f(x) * ddx2};
  
  // Defining the tridiagonal matrix A
  mat A (x.n_elem, x.n_elem, arma::fill::zeros);
  A.diag() += 2;
  A.diag(1) += -1;
  A.diag(-1) += -1;

  // Defining the augmented matrix Ag = [A | g]
  mat Ag (x.n_elem, x.n_elem + 1, arma::fill::zeros);
  Ag.submat(0, 0, x.n_elem - 1, x.n_elem - 1) = A;
  Ag.insert_cols(x.n_elem, g);


  cout << Ag << endl;
    
  return 0;
}