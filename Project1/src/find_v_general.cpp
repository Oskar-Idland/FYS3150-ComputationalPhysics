#include <iostream>
#include <vector>
#include <chrono>
#include "../include/find_v_general.h"
using namespace std;



void fillArray(const vector<float> &v, float *const arr) {
  for (size_t i {}; i < v.size(); ++i)
    arr[i] = v.at(i);
}

void fillArray(const vector<double> &v, double *const arr) {
  for (size_t i {}; i < v.size(); ++i)
    arr[i] = v.at(i);
}

void fillVector(const float *const arr, vector<float> &v) {
  for (size_t i {}; i < v.size(); ++i)
    v.at(i) = arr[i];
}

vector<float> find_v_general(const vector<float> &a, const vector<float> &b, const vector<float> &c, const vector<double> &g) {
  const int n = g.size();

  // const vector<double> *const a_ptr {&a};
  // const vector<double> *const b_ptr {&b};
  // const vector<double> *const c_ptr {&c};
  // const vector<double> *const g_ptr {&g};


  float *a_arr = new float [n];
  float *b_arr = new float [n];
  float *c_arr = new float [n];
  double *g_arr = new double [n];
  fillArray(a, a_arr);
  fillArray(b, b_arr);
  fillArray(c, c_arr);
  fillArray(g, g_arr);

  

  // Initialize and fill first row of augmented matrix
  vector<float> row1 (n+1, 0.0);
  float *row1_arr = new float [n+1];
  fillArray(row1, row1_arr);

  row1_arr[0] = b_arr[0];
  row1_arr[1] = c_arr[0];
  row1_arr[n] = g_arr[0];

  // Initialize second row of augmented matrix
  vector<float> row2 (n+1, 0.0);
  float *row2_arr = new float [n+1];
  fillArray(row2, row2_arr);

  // Initialize vector used to store modified diagonal elements
  vector<float> diag (n, 0.0);
  float *diag_arr = new float [n];
  fillArray(diag, diag_arr);

  // Initialize vector with numerical solution
  vector<float> v (n, 0.0);
  float *v_arr = new float [n];
  fillArray(v, v_arr);
  
  // Implementation of the algorithm from Problem 6
  auto t1 = chrono::high_resolution_clock::now();
  for (size_t i {}; i < n-1; ++i) { 
    // Remove subdiagonal
    // Fill row i+1 of augmented matrix
    row2_arr[i] = a_arr[i];
    row2_arr[i+1] = b_arr[i+1];
    if (i < n-2)
      row2_arr[i+2] = c_arr[i+1];
    row2_arr[n] = g_arr[i+1];

    row2_arr[i+1] -= row1_arr[i+1] * (row2_arr[i] / row1_arr[i]);
    // g_i+1 -= g_i * (a_i / b_i)
    row2_arr[n] -= row1_arr[n] * (row2_arr[i] / row1_arr[i]);
    // a_i -= b_i * (a_i / b_i)
    row2_arr[i] = 0.0;

    // Store modified diagonal element
    diag_arr[i] = row1_arr[i];
    // Store modified g_i
    v_arr[i] = row1_arr[n];
    // Replace row i with row i+1
    row1 = row2;
  }
  auto t2 = chrono::high_resolution_clock::now();
  cout << "First loop: " << chrono::duration<double>(t2 - t1).count() << " seconds" << endl;
  // Store last modified diagonal element
  diag_arr[n-1] = row2_arr[n-1];
  // Store modified g_(n-1)
  v_arr[n-1] = row2_arr[n];

  auto t3 = chrono::high_resolution_clock::now();
  for (int i {n-1}; i-- > 1;) { 
    // Remove superdiagonal and normalize diagonal elements
    v_arr[i] /= diag_arr[i];
    v_arr[i-1] -= c_arr[i-1] * v_arr[i]; 
  }
  auto t4 = chrono::high_resolution_clock::now();
  cout << "Second loop: " << chrono::duration<double>(t4 - t3).count() << " seconds" << endl;

  // Impose boundary conditions
  v_arr[0] = 0.0;
  v_arr[n-1] = 0.0;

  for (size_t i {}; i < n; ++i)
    v_arr[i] *= -1.0;

  fillVector(v_arr, v);
  delete [] a_arr;
  delete [] b_arr;
  delete [] c_arr;
  delete [] g_arr;
  delete [] row1_arr;
  delete [] row2_arr;
  delete [] diag_arr;
  delete [] v_arr;
  return v;
}