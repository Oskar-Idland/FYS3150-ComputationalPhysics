#include <iostream>
#include <vector>
#include <chrono>
#include "../include/find_v_general.h"
using namespace std;

// [Achievemt unlocked🎖️!: Stack Overflow🚽🪠]

vector<double> find_v_general(const vector<double> &a, const vector<double> &b, const vector<double> &c, const vector<double> &g) {
  const int n = g.size();

  // Initialize first and second row of augmented matrix
  double row1_i  {};
  double row1_i1 {};
  double row1_n  {};
  double row2_i  {};
  double row2_i1 {};
  double row2_i2 {};
  double row2_n  {};

  row1_i = b.at(0);
  row1_i1 = c.at(0);
  row1_n = g.at(0);

  
  // Initialize vector used to store modified diagonal elements
  vector<double> diag (n, 0.0);

  // Initialize vector with numerical solution
  vector<double> v (n, 0.0);

  
  // Implementation of the algorithm from Problem 6
  for (size_t i = {}; i < (n-1); ++i) {

    // Remove subdiagonal
    // Fill row i+1 of augmented matrix
    row2_i = a.at(i);
    row2_i1 = b.at(i+1);

    if (i < n-2)
      row2_i2 = c.at(i+1);
    
    row2_n = g.at(i+1);
   
    // g_i+1 -= g_i * (a_i / b_i)
    row2_i1 -= row1_i1 * (row2_i / row1_i);
    
    // a_i -= b_i * (a_i / b_i)
    row2_n -= row1_n * (row2_i / row1_i);
    row2_i = 0.0;

    // Store modified diagonal element
    diag.at(i) = row1_i;
    // Store modified g_i
    v.at(i) = row1_n;
    // Replace row i with row i+1

    row1_i = row2_i1;
    row1_i1 = row2_i2;
    row1_n = row2_n;
  }
  double last_diag = row2_i2;

  // Store last modified diagonal element
  diag.at(n-1) = last_diag;
  // Store modified g_(n-1)
  v.at(n-1) = row2_n;
  
  for (int i {n-1}; i-- > 1;) { 
    // Remove superdiagonal and normalize diagonal elements
    v.at(i) /= diag.at(i);
    v.at(i-1) -= c.at(i-1) * v.at(i); 
  }

  // Impose boundary conditions
  v.at(0) = 0.0;
  v.at(n-1) = 0.0;
  
  // Fixing the sign of the numerical solution
  for (auto &v_i : v) {v_i *= -1.0;}

  return v;
}