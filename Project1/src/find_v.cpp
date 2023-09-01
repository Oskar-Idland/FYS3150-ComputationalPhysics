#include <iostream>
#include <vector>
#include "../include/find_v.h"

using namespace std;

vector<double> find_v(const vector<double>& a, const vector<double>& b, const vector<double>& c, const vector<double>& g) {
    int n = static_cast<int>(g.size());

    // Initialize first row of augmented matrix
    vector<double> row1(n + 1, 0.0);
    // Initialize secound row of augmented matrix
    vector<double> row2(n + 1, 0.0);
    // Initialize vector used to store modified diagonal elements
    vector<double> diag(n, 0.0);
    // Initialize vector with numerical solution
    vector<double> v(n, 0.0);

    // Fill first row of augmented matrix
    row1[0] = b[0];
    row1[1] = c[0];
    row1[n] = g[0];

    // Implementation of the algorithm
    for (int i = 0; i < n - 1; i++) {
      // Remove subdiagonal
      // Fill row i+1 of augmented matrix
        row2[i] = a[i];
        row2[i + 1] = b[i + 1];
        row2[i + 2] = c[i];
        row2[n] = g[i + 1];

        double F = row2[i] / row1[i];
        for (int j = 0; j <= n; ++j) {
            row2[j] -= row1[j] * F;
        }
          // Store modified diagonal element
        diag[i] = row1[i];
        // Store modified g_i
        v[i] = row1[n];
        // Replace row i with row i+1
        row1 = row2;
    }
    // Store last modified diagonal element
    diag[n - 1] = row2[n - 1];
    // Store modified g_(n-1)
    v[n - 1] = row2[n];

    for (int i = n - 1; i >= 1; --i) {
      // Remove superdiagonal and normalize diagonal elements
        v[i] /= diag[i];
        v[i - 1] -= c[i - 1] * v[i];
    }
    
    // Impose boundary conditions
    v[0] = 0.0;
    v[n - 1] = 0.0;

    for (int i = 0; i < n; ++i) {
        v[i] *= -1.0;
    }

    return v;
}
