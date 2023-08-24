#include <iostream>
#include <iomanip>
#include <armadillo>
#include <string>
#include <fstream>
#include "problem3.h"

using namespace std;

double f(double x){
    return - 100*exp(- 10*x);
}

void problem3(){
    arma::vec x {arma::linspace <arma::vec>(0, 1, 100)};
    arma::vec v (100);

    double dx {};                   // difference in x between data points
    double ddvddx {};               // double derivative of v(x)

    dx = x.at(1) - x.at(0);                      

    for (size_t i {1}; i < 100; ++i){
        dvdx += ddvddx*dx;
        v.at(i) = v.at(i-1) + dvdx*dx;
    }

    string filename = "x_v.txt";
    ofstream ofile;
    ofile.open(filename);
    ofile << "x" << "      " << "v" << endl;
    for (size_t i {0}; i < 100; ++i){
        ofile << fixed << setprecision(4) 
              << x.at(i) << " " << v.at(i) 
              << endl;
    }
    ofile.close();
}
