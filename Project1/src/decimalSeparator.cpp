#include <string>
#include "../include/decimalSeparator.h"

std::string decSeparator(int n) {
    std::string s {std::to_string(n)};
    int pos {static_cast<int>(std::to_string(double(n)).find('.'))};
    int i {pos - 3};
    while (i > 0) {
        s.insert(i, "'");
        i -= 3;
    }
    return s;
}