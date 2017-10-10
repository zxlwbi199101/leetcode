/*
 * https://leetcode.com/problems/sum-of-square-numbers/description/
 *
 * Given a non-negative integer c, your task is to decide whether there're
 * two integers a and b such that a2 + b2 = c.
 *
 * Example 1:
 * Input: 5
 * Output: True
 * Explanation: 1 * 1 + 2 * 2 = 5
 *
 * Example 2:
 * Input: 3
 * Output: False
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



