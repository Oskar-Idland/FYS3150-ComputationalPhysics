#include "../include/write_to_file.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

void write_to_file(const vector<double> &v1, const vector<double> &v2, string filename){

    ofstream ofile;
    ofile.open("./data/" + filename);
    ofile << "   x" << "   " << "   u" << endl;
    ofile << fixed << setprecision(10); 
    for (size_t i {0}; i < v1.size(); i++){
        ofile << v1.at(i) << " " << v2.at(i) << endl;
    }
    ofile.close();
}