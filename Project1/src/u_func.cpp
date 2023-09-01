#include "../include/u_func.h"
#include <cmath>
#include <vector>
using std::vector;

vector<double> u_func (vector<double> x){
    vector<double> u (x.size());
    for (size_t i {}; i < x.size(); ++i)
        u.at(i) = 1 - (1-exp(-10))*x.at(i) - exp(-10*x.at(i));
    return u;
}