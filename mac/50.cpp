#include "header.hpp"

class Solution {
 public:
  double myPow(double x, int n) {
    if (n > 0) {
      cout << "n>0" << endl;
      double result = 1;
      while (n--) {
        result *= x;
      }
      return result;
    } else if (n == 0) {
      return double(1);
    } else {
      cout << "n>0" << endl;

      double result = 1;
      double reverse = 1.0 / x;
      cout << result << endl;
      while (n++) {
        result *= reverse;
        cout << result << endl;
      }
      return result;
    }
  }
};
