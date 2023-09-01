/*
TODO:
- find out why the find_v function gives us a numerical solution that is flipped
- what is the special algorithm and what is the general algorithm?
- run with n up to 10^6 at least three times with both algorithms for task 10. fill runtime values in runtimes.txt
- run general algorithm with n = 10^7 once for task 8
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <armadillo>
#include <vector>
#include <chrono>
#include "../include/write_to_file.h"
#include "../include/u_func.h"
#include "../include/f.h"
#include "../include/find_v.h"
using namespace std;
using arma::vec, arma::linspace, arma::mat;

int main()
{
  //------Problem 2------
    int n {100};
    vec x {arma::linspace<vec>(0.0, 1.0, n)};
    vec u {u_func(x)};
    write_to_file(x, u, "x_u.txt");

    //------Problem 7 & 8-------
    // Initialize v-vector
    vec v {};

    vector<int> n_values {10, 100, 1000, 10000, 100000};
    for (auto n : n_values) {
        // Initial x-vector, dx^2 and g-vector
        std::vector<double> x;

        for (int i = 0; i < n; ++i) {
            double value = static_cast<double>(i) / (n - 1); // Values between 0.0 and 1.0
            x.push_back(value);
        }

        double ddx2 {std::pow(x.at(1) - x.at(0), 2)};
        std::vector<double> g(n);
        for (int i = 0; i < n; ++i) {
            g.at(i) = -f(x.at(i)) * ddx2;
        }


        // Initialize diagonal vectors
        std::vector<double> a(n - 1, -1.0);
        std::vector<double> b(n, 2.0);
        std::vector<double> c(n - 1, -1.0);

        // Find numerical solution v and take the time
        auto t1 = chrono::high_resolution_clock::now();
        v = find_v(a, b, c, g);
        auto t2 = chrono::high_resolution_clock::now();
        cout << "Time elapsed for n = " << n << ": " << chrono::duration<double>(t2 - t1).count() << " seconds" << endl;

        // Writing the numerical solution to file
        string filename {"x_v_" + to_string(n) + ".txt"};
        write_to_file(x, v, filename);

        // Writing the exact solution to file
        string filename_exact {"x_u_" + to_string(n) + ".txt"};
        u = u_func(x);
        write_to_file(x, u, filename_exact);
    }

  return 0;
}