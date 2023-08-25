#include <iostream>
#include <cmath>
#include <iomanip>
#include <armadillo>
#include "write_to_file.h"
#include "u.h"
#include "f.h"

using namespace std;
using arma::vec, arma::linspace, arma::mat;

int main()
{ 
  //------Problem 2------
  vec x {arma::linspace<vec>(0.0, 1.0, 4)};
  vec v {u(x)};
  // write_to_file(x, v, "x_u.txt");

  //------Problem 7-------
  double ddx2 {std::pow(x.at(1) - x.at(0), 2)};
  vec g {- f(x) * ddx2};
  
  mat A (x.n_elem, x.n_elem, arma::fill::zeros);
  A.diag() += 2;
  A.diag(1) += -1;
  A.diag(-1) += -1;

  A.insert_cols(x.n_elem, g);

  cout << A << endl;
    
  return 0;
}