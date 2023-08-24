#include <iostream>
#include <armadillo>
#include <vector> 
#include <cmath>

#include "../include/libnpy/include/npy.hpp"
//#include "../inlclude/include/npy/npz.h"



using namespace std; 


double f(double x){
    return 100*exp(-10*x);
}

double u(double x){
    return 1 - (1 - exp(-10))*x - exp(-10*x);
}

int main() {

    arma::vec v = arma::linspace(0, 1, 101);
    vector<float> inputs; 
    vector<float> outputs;
    for (float n : v){
        //cout << "x-values:" << n << " ||  Functionvalue:" << u(n) << endl;
        inputs.push_back(n);
        outputs.push_back(u(n));

    }
    const std::string path1{"./out.npy"};
    const std::string path2{"./in.npy"};

    const bool fortran_order{false};
    const std::vector<long unsigned> shape{1, 101};

    npy::SaveArrayAsNumpy(path1, fortran_order, shape.size(), shape.data(), outputs.data());
    npy::SaveArrayAsNumpy(path2, fortran_order, shape.size(), shape.data(), inputs.data());
    return 0;
}




