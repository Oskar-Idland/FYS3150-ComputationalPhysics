#include "../include/write_to_file.h"
#include <iostream>
#include <armadillo>
#include <string>
#include <iomanip>

using arma::vec;
using namespace std;

void write_to_file(vec v1, vec v2, string filename){

    ofstream ofile;
    ofile.open("./data/" + filename);
    ofile << "   x" << "   " << "   u" << endl;
    for (size_t i {0}; i < v1.size(); i++){
        ofile << fixed << setprecision(10) 
              << v1[i] << " " << v2[i] 
              << endl;
    }
    ofile.close();
}