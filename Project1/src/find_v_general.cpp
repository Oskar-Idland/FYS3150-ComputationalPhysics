#include <iostream>
#include <vector>
#include "../include/find_v_general.h"
using namespace std;

vector<double> find_v_general(vector<double> a, vector<double> b, vector<double> c, vector<double> g) {
  int n = g.size();

  // Initialize and fill first row of augmented matrix
  vector<double> row1 (n+1, 0.0);
  row1.at(0) = b.at(0);
  row1.at(1) = c.at(0);
  row1.at(n) = g.at(0);

  // Initialize second row of augmented matrix
  vector<double> row2 (n+1, 0.0);

  // Initialize vector used to store modified diagonal elements
  vector<double> diag (n, 0.0);
  // Initialize vector with numerical solution
  vector<double> v (n, 0.0);
  
  // Implementation of the algorithm from Problem 6
  for (size_t i {}; i < n-1; ++i) { 
    // Remove subdiagonal
    // Fill row i+1 of augmented matrix
    row2.at(i) = a.at(i);
    row2.at(i+1) = b.at(i+1);
    if (i < n-2)
      row2.at(i+2) = c.at(i+1);
    row2.at(n) = g.at(i+1);

    row2.at(i+1) -= row1.at(i+1) * (row2.at(i) / row1.at(i));
    // g_i+1 -= g_i * (a_i / b_i)
    row2.at(n) -= row1.at(n) * (row2.at(i) / row1.at(i));
    // a_i -= b_i * (a_i / b_i)
    row2.at(i) = 0.0;

    // Store modified diagonal element
    diag.at(i) = row1.at(i);
    // Store modified g_i
    v.at(i) = row1.at(n);
    // Replace row i with row i+1
    row1 = row2;
  }
  // Store last modified diagonal element
  diag.at(n-1) = row2.at(n-1);
  // Store modified g_(n-1)
  v.at(n-1) = row2.at(n);

  for (int i {n-1}; i-- > 1;) { 
    // Remove superdiagonal and normalize diagonal elements
    v.at(i) /= diag.at(i);
    v.at(i-1) -= c.at(i-1) * v.at(i); 
  }

  // Impose boundary conditions
  v.at(0) = 0.0;
  v.at(n-1) = 0.0;

  for (size_t i {}; i < n; ++i)
    v.at(i) *= -1.0;

  return v;
}