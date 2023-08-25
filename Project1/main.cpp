#include <iostream>
#include <iomanip>
#include <armadillo>
// #include "problem2.h"
#include "A.h"

using namespace std;
int main()
{
  // Print a message to screen
  // cout << "Hello, World!\n";
  // problem2(); 
  arma::vec x = arma::linspace<arma::vec>(0, 1, 10);
  arma::vec y = A(x);
  cout << y << endl;
  // Return 0 when done
  return 0;
}