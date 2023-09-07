#include "../include/write_to_file.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

void write_to_txt_file(const vector<double> &v1, const vector<double> &v2, string filename){
    string s {""};
    for (size_t i {0}; i < v1.size(); i++){
        s += to_string(v1.at(i)) + " " + to_string(v2.at(i)) + "\n";
    }

    ofstream ofile;
    ofile.open("./data/" + filename);
    ofile << fixed << setprecision(10); 
    ofile << s;
    ofile.close();
}

/*
Writes arrays to binary files
@param v1: x values
@param v2: y values
@param filename: name of file. DO NOT INCLUDE FILE EXTENSION
*/
void write_to_bin_file(const vector<double> &v1, const vector<double> &v2, string filename) {
    int n = v1.size();
    double (*data)[2] = new double[n][2];

    for (size_t i {}; i < n; ++i) {
        data[i][0] = v1.at(i);
        data[i][1] = v2.at(i);
    }

    std::ofstream outfile("data/" + filename, std::ios::out | std::ios::binary);
    if (!outfile) {
        std::cerr << "Error opening file for writing" << std::endl;
    }

    outfile << fixed << setprecision(1); 
    outfile.write(reinterpret_cast<const char*>(data), sizeof(double) * n * 2);
    outfile.close();
    delete[] data;
}