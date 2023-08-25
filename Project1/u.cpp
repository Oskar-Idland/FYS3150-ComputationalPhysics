#include "u.h"
#include <cmath>

double u (double x){
    return 1 - (1-exp(-10))*x - exp(-10*x);
}