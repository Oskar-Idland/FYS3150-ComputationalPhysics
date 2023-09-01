#include <armadillo>
#include "../include/find_v.h"
using arma::vec;

vec find_v(vec a, vec b, vec c, vec g) {
  int n {g.n_elem};

  // Initialize and fill first row of augmented matrix
  vec row1 (n + 1, arma::fill::zeros);
  // vec *row1_ptr = {&row1}; 
  row1.at(0) = b.at(0);
  row1.at(1) = c.at(0);
  row1.at(n) = g.at(0);

  // Initialize second row of augmented matrix
  vec row2 (n + 1, arma::fill::zeros);
  // vec *row2_ptr = {&row2};

  // Initialize vector used to store modified diagonal elements
  vec diag (n, arma::fill::zeros);
  // Initialize vector with numerical solution
  vec v (n, arma::fill::zeros);
  
  // Implementation of the algorithm from Problem 6
  auto t1 = std::chrono::high_resolution_clock::now();
  for (size_t i {}; i < n-1; ++i) { 
    // Remove subdiagonal
    // Fill row i+1 of augmented matrix
    row2.at(i) = a.at(i);
    row2.at(i+1) = b.at(i+1);
    row2.at(i+2) = c.at(i+1);
    row2.at(n) = g.at(i+1);

    row2 -= row1 * (row2.at(i) / row1.at(i));

    // Store modified diagonal element
    diag.at(i) = row1.at(i);
    // Store modified g_i
    v.at(i) = row1.at(n);
    // Replace row i with row i+1
    row1 = row2;
  }
  auto t2 = std::chrono::high_resolution_clock::now();
  std::cout << "Time for first loop: " << std::chrono::duration<double>(t2 - t1).count() << " seconds" << std::endl;
  // Store last modified diagonal element
  diag.at(n-1) = row2.at(n-1);
  // Store modified g_(n-1)
  v.at(n-1) = row2.at(n);

  auto t3 = std::chrono::high_resolution_clock::now();
  for (int i {n-1}; i-- > 1;) { 
    // Remove superdiagonal and normalize diagonal elements
    v.at(i) /= diag.at(i);
    v.at(i-1) -= c.at(i-1) * v.at(i); 
  }
  auto t4 = std::chrono::high_resolution_clock::now();
  std::cout << "Time for second loop: " << std::chrono::duration<double>(t4 - t3).count() << " seconds" << std::endl;

  // Impose boundary conditions
  v.at(0) = 0;
  v.at(n-1) = 0;
  v *= -1;

  return v;
}