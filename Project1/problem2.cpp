#include <iostream>
#include <iomanip>
#include <armadillo>
#include <string>
#include <fstream>
#include "problem2.h"
#include "u.h"

using namespace std;
using arma::vec;

void problem2(){
    vec x {arma::linspace<vec>(0.0, 1.0, 100)};

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
}