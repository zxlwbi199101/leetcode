/*
 * https://leetcode.com/problems/sum-of-two-integers/#/description
 *
 * Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
 *
 */

#include <iostream>
using namespace std;

// solution 1
class Solution {
public:
  int getSum(int a, int b) {
    int sum = a;

    while (b != 0) {
      sum = a ^ b;
      b = (a & b) << 1;
      a = sum;
    }

    return sum;
  }
};


// test
int main() {
  Solution solution;

  cout << solution.getSum(1, 3) << endl;

  return 0;
}


