/*
 * https://leetcode.com/problems/valid-perfect-square/description/
 *
 * Given a positive integer num, write a function which returns True if num
 * is a perfect square else False.
 *
 * Note: Do not use any built-in library function such as sqrt.
 *
 * Example 1:
 *
 * Input: 16
 * Returns: True
 * Example 2:
 *
 * Input: 14
 * Returns: False
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
  bool isPerfectSquare(int num) {
    int i = 1, j = num;

    while (i < j) {
      int mid = (i + j) / 2;

      if (num / mid < mid) j = mid - 1;
      else if (mid * mid == num) return true;
      else i = mid + 1;
    }

    return i * i == num;
  }
};

// test
int main() {
  Solution solution;
  cout << solution.isPerfectSquare(9) << endl;
  cout << solution.isPerfectSquare(1) << endl;
  cout << solution.isPerfectSquare(2) << endl;
  cout << solution.isPerfectSquare(25) << endl;
  cout << solution.isPerfectSquare(27) << endl;

  return 0;
}



