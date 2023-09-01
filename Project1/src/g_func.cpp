#include "../include/g_func.h"
#include <cmath>
#include <vector>
using std::vector;

vector<double> g_func(vector<double> x, double ddx2) {
    vector<double> g (x.size());
    for (size_t i {}; i < x.size(); ++i)
        g.at(i) = - 100.0 * exp(-10.0 * x.at(i)) * ddx2;
    return g;
}