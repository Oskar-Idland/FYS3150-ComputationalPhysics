#include <iostream>
#include <iomanip>
#include <armadillo>
#include <string>
#include <fstream>
#include <chrono>
#include "problem3.h"

using namespace std;

void problem3(){
    // Start measuring time
    auto t1 = chrono::high_resolution_clock::now();

    arma::vec x {arma::linspace <arma::vec>(0, 1, 100)};
    arma::vec v {0};

    double dx = x.at(1) - x.at(0);                // difference in x between data points

    double ddvddx = {- 100*exp(- 10*x.at(0))};    // double derivative of v(x)
    double dvdx = {ddvddx*dx};                    // derivative of v(x)

    for (int i {1}; i < 100; ++i){
        ddvddx = - 100*exp(- 10*x.at(i));
        dvdx += ddvddx*dx;
        v.at(i) = v.at(i-1) + dvdx*dx;
    }

    string filename = "x_v.txt";
    ofstream ofile;
    ofile.open(filename);
    ofile << "x" << "      " << "v" << endl;
    for (int i {0}; i < 100; ++i){
        ofile << fixed << setprecision(4) 
              << x.at(i) << " " << v.at(i) 
              << endl;
    }
    ofile.close();

    // Stop measuring time
    auto t2 = chrono::high_resolution_clock::now();

    // Calculate the elapsed time
    // We use chrono::duration<double>::count(), which by default returns duration in seconds
    double duration_seconds = chrono::duration<double>(t2 - t1).count();

    // Print the elapsed time
    cout << duration_seconds << " s" << endl;
}
