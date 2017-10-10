/*
 * https://leetcode.com/problems/sum-of-square-numbers/description/
 *
 * We define the Perfect Number is a positive integer that is equal to the sum
 * of all its positive divisors except itself.
 *
 * Now, given an integer n, write a function that returns true when it is a
 * perfect number and false when it is not.
 * Example:
 * Input: 28
 * Output: True
 * Explanation: 28 = 1 + 2 + 4 + 7 + 14
 * Note: The input number n will not exceed 100,000,000. (1e8)
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <math.h>
#include <ctype.h>
using namespace std;

// solution 1
class Solution {
public:
  // bool judgeSquareSum(int c) {
  //   for (double a = 0; a * a <= c; a++) {
  //     double b = sqrt(c - a * a);
  //     if (b == (int)b) return true;
  //   }

  //   return false;
  // }

  bool judgeSquareSum(int c) {
    if (!c) return true;
    int i = 0, j = (int)sqrt(c - 1) + 1;

    while (i <= j) {
      int result = i * i + j * j;
      if (result == c) return true;

      if (result < c) i++;
      else j--;
    }

    return false;
  }
};

// test
int main() {
  Solution solution;
  cout << solution.judgeSquareSum(2147483646) << endl;
  cout << solution.judgeSquareSum(4) << endl;
  cout << solution.judgeSquareSum(2) << endl;

  return 0;
}



