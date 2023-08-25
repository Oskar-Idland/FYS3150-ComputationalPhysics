#include <iostream>
#include <iomanip>
#include <armadillo>
#include <string>
#include <fstream>
#include "problem2.h"
#include "u.h"
#include "write_to_file.h"

using namespace std;
using arma::vec;

vec f (vec x){
    return 1 - (1-exp(-10))*x - exp(-10*x);
}

void problem2(){
    vec x {arma::linspace<vec>(0.0, 1.0, 100)};
    vec u {f(x)};
    write_to_file(x, u, "xu_test.txt");
}