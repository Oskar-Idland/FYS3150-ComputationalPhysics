#include <iostream>
#include <armadillo>
#include <string>
#include <fstream>
#include <chrono>
#include "problem2.h"

using namespace std;
using namespace arma;


vec f(vec x) {
    return 1 - (1-exp(-10))*x - exp(-10*x);
}

void problem2(){
    vec x {linspace<vec>(0, 1, 100)};

    vec u {f(x)};

    string filename = "x_u.txt";
    ofstream ofile;
    ofile.open(filename);
    for (size_t i = 0; i < x.size(); i++) {
        ofile << x[i] << " " << u[i] << endl;
    }
    ofile.close();
}