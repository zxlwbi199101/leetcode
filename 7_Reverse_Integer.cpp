/*
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * Reverse digits of an integer.
 *
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 *
 * click to show spoilers.
 *
 * Note:
 * The input is assumed to be a 32-bit signed integer. Your function should
 * return 0 when the reversed integer overflows.
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
  int reverse(int x) {
    bool isMinus = x < 0;
    if (isMinus) x *= -1;

    int reverted = 0;
    while (x) {
      if ((INT_MAX - x % 10) / 10 < reverted) return 0;
      reverted = reverted * 10 + x % 10;
      x /= 10;
    }

    return (isMinus ? -1 : 1) * reverted;
  }
};

// test
int main() {
  Solution solution;
  cout << solution.reverse(123) << endl;

  return 0;
}



