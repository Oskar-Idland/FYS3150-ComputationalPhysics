#include <iostream>
#include <armadillo>
#include <string>

using arma::vec;
using namespace std;

void write_to_file(vec v1, vec v2){

    string filename = "x_u_test.txt";
    ofstream ofile;
    ofile.open(filename);
    ofile << "   x" << "   " << "   u" << endl;
    for (size_t i {0}; i < v1.size(); i++){
        ofile << fixed << setprecision(4) 
              << v1[i] << " " << v2[i] 
              << endl;
    }
    ofile.close();
}