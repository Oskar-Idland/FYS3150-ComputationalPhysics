#include <iostream>
#include <vector>
#include <chrono>
#include <omp.h>
#include "../include/find_v_general.h"
using namespace std;


vector<double> find_v_general(const vector<double> &a, const vector<double> &b, const vector<double> &c, const vector<double> &g) {
  const int n = g.size();

  const vector<double> *a_ptr {&a};
  const vector<double> *b_ptr {&b};
  const vector<double> *c_ptr {&c};
  const vector<double> *g_ptr {&g};

  // Initialize and fill first row of augmented matrix
  // Memory is allocated on the heap to avoid overflow (which has happened [Achievemt unlocked🎖️!: Stack Overflow🚽🪠])
  vector<double> *row1_ptr = new vector<double> (n+1, 0.0);

  row1_ptr->operator[](0) = b_ptr->operator[](0);
  row1_ptr->operator[](1) = c_ptr->operator[](0);
  row1_ptr->operator[](n) = g_ptr->operator[](0);

  // Initialize second row of augmented matrix
  vector<double> *row2_ptr = new vector<double> (n+1, 0.0);
  

  // Initialize vector used to store modified diagonal elements
  vector<double> *diag_ptr = new vector<double> (n, 0.0);

  // Initialize vector with numerical solution
  // Exempt from the heap because it needs to be returned
  vector<double> v (n, 0.0);
  vector<double> *v_ptr {&v};
  
  // Implementation of the algorithm from Problem 6
  for (size_t i = {}; i < (n-1); ++i) { // This loop is 10'000 X slower than the last loop

    // Remove subdiagonal
    // Fill row i+1 of augmented matrix
    row2_ptr->operator[](i) = a_ptr->operator[](i);
    row2_ptr->operator[](i+1) = b_ptr->operator[](i+1);

    if (i < n-2)
      row2_ptr->operator[](i+2) = c_ptr->operator[](i+1);
    
    row2_ptr->operator[](n) = g_ptr->operator[](i+1);
   
    // g_i+1 -= g_i * (a_i / b_i)
    row2_ptr->operator[](i+1) -= row1_ptr->operator[](i+1) * (row2_ptr->operator[](i) / row1_ptr->operator[](i));
    
    // a_i -= b_i * (a_i / b_i)
    row2_ptr->operator[](n) -= row1_ptr->operator[](n) * (row2_ptr->operator[](i) / row1_ptr->operator[](i));
    row2_ptr->operator[](i) = 0.0;

    // Store modified diagonal element
    diag_ptr->operator[](i) = row1_ptr->operator[](i);
    // Store modified g_i
    v_ptr->operator[](i) = row1_ptr->operator[](n);
    // Replace row i with row i+1
    // This operation is 1'000 X slower than the rest of the loop
    // Should be optimized if possible
    delete row1_ptr;
    row1_ptr = row2_ptr;
    row2_ptr = new vector<double> (n+1, 0.0);
  }

  // Store last modified diagonal element
  diag_ptr->operator[](n-1) = row2_ptr->operator[](n-1);
  // Store modified g_(n-1)
  v_ptr->operator[](n-1) = row2_ptr->operator[](n);
  
  
  for (int i {n-1}; i-- > 1;) { 
    // Remove superdiagonal and normalize diagonal elements
    v_ptr->operator[](i) /= diag_ptr->operator[](i);
    v_ptr->operator[](i-1) -= c_ptr->operator[](i-1) * v_ptr->operator[](i); 
  }

  // Impose boundary conditions
  v_ptr->operator[](0) = 0.0;
  v_ptr->operator[](n-1) = 0.0;

  // Fixing the sign of the numerical solution
  for (size_t i {}; i < n; ++i) {v_ptr->operator[](i) *= -1.0;}

  delete row1_ptr; 
  delete row2_ptr;
  delete diag_ptr;
  return *v_ptr;
}