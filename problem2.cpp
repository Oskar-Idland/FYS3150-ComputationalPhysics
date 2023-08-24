#include <iostream>
#include <armadillo>
#include <string>
#include <fstream>
#include <chrono>
#include "problem2.h"

using namespace std;


void problem2(){
    // Start measuring time
    auto t1 = std::chrono::high_resolution_clock::now();

    arma::vec x {arma::linspace<arma::vec>(0, 1, 100)};

    arma::vec u {1 - (1-exp(-10))*x - exp(-10*x)};

    std::string filename = "x_u.txt";
    std::ofstream ofile;
    ofile.open(filename);
    ofile  << x << endl;
    ofile  << u << endl;
    ofile.close();

    // Stop measuring time
    auto t2 = std::chrono::high_resolution_clock::now();

    // Calculate the elapsed time
    // We use chrono::duration<double>::count(), which by default returns duration in seconds
    double duration_seconds = std::chrono::duration<double>(t2 - t1).count();

    // Print the elapsed time
    cout << duration_seconds << " s" << endl;
}