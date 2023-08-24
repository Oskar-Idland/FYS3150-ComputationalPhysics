#include <iostream>
#include <armadillo>

using namespace std;
int main()
{
  // Print a message to screen
  cout << "Hello, World!\n";
  arma::vec A = arma::vec(2);
  cout << A << endl;
  
  // Return 0 when done
  return 0;
}