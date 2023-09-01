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
#include <vector>
#include <chrono>
#include "../include/write_to_file.h"
#include "../include/u_func.h"
#include "../include/g_func.h"
#include "../include/find_v_general.h"
using namespace std;

int main()
{
  //------Problem 2------
    int n {100};
    vector<double> x (n, 1.0);
    for (size_t i {}; i < n; ++i)
      x.at(i) *= i*1.0/n;
    vector<double> u {u_func(x)};
    write_to_file(x, u, "x_u.txt");

    //------Problem 7 & 8-------
    // Initialize v-vector
    vector<double> v {};

    vector<int> n_values {10, 100, 1'000, 10'000, 100'000, 1'000'000};
    for (auto n : n_values) {
        // Initial x-vector, dx^2 and g-vector
        vector<double> x (n, 1.0);
        for (size_t i {}; i < n; ++i)
          x.at(i) *= i*1.0/(n-1);
        double ddx2 {pow(x.at(1) - x.at(0), 2)};
        vector<double> g = g_func(x, ddx2); 

        // Initialize diagonal vectors
        vector<double> a (n-1, -1.0);
        vector<double> b (n, 2.0);
        vector<double> c (n-1, -1.0);
        
        // Find numerical solution v and take the time
        auto t1 = chrono::high_resolution_clock::now();
        v = find_v_general(a, b, c, g);
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