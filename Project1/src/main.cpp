/*
TODO:
- Write a set amount of digits to file
- Move the makefile to the root folder and make it able to output .o files to the bin folder

*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <armadillo>
#include <vector>
#include "../include/write_to_file.h"
#include "../include/u.h"
#include "../include/f.h"
#include "../include/find_v.h"
using namespace std;
using arma::vec, arma::linspace, arma::mat;

int main()
{ 
  //------Problem 2------
    int n {100};
    vec x {arma::linspace<vec>(0.0, 1.0, n)};
    vec v {u(x)};
    write_to_file(x, v, "x_u.txt");

    //------Problem 7-------
    // Defining the step size d^2x/dx^2 and the vector g

    vector<int> n_values {10, 100, 1000};
    for (auto n : n_values) {
        vec x {arma::linspace<vec>(0.0, 1.0, n)};
        double ddx2 {std::pow(x.at(1) - x.at(0), 2)};
        vec g {- f(x) * ddx2};

        // Defining the tridiagonal matrix A
        mat A (x.n_elem, x.n_elem, arma::fill::zeros);
        A.diag() += 2;
        A.diag(1) += -1;
        A.diag(-1) += -1;

        // Finding the solution v
        v = find_v(g, A);

        // Writing the result to file
        string filename {"x_v_" + to_string(n) + ".txt"};
        write_to_file(x, v, filename);
    }

  return 0;
}