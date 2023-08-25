#include <iostream>
#include <iomanip>
#include <armadillo>
#include "u.h"
#include "write_to_file.h"

using namespace std;
using arma::vec;
int main()
{
  // Print a message to screen
  cout << "Hello, World!\n";
  
  //------Problem 2------
  vec x {arma::linspace<vec>(0.0, 1.0, 100)};
  vec v {u(x)};
  write_to_file(x, v, "x_u.txt");
  
  return 0;
}