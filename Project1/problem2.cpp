#include <iostream>
#include <iomanip>
#include <armadillo>
#include <string>
#include <fstream>
#include <chrono>
#include "problem2.h"

using namespace std;

double u (double x){
    return 1 - (1-exp(-10))*x - exp(-10*x);
}

void problem2(){
    // Start measuring time
    auto t1 = chrono::high_resolution_clock::now();

    arma::vec x {arma::linspace<arma::vec>(0.0, 1.0, 100)};


    string filename = "x_u.txt";
    ofstream ofile;
    ofile.open(filename);
    ofile << "   x" << "   " << "   u" << endl;
    for (float i : x){
        ofile << fixed << setprecision(4) 
              << i << " " << u(i) 
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