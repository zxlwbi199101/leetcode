/*
 * https://leetcode.com/problems/integer-break/description/
 *
 * Given a positive integer n, break it into the sum of at least two positive
 * integers and maximize the product of those integers. Return the maximum
 * product you can get.
 *
 * For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36
 * (10 = 3 + 3 + 4).
 *
 * Note: You may assume that n is not less than 2 and not larger than 58.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <math.h>
#include <ctype.h>
#include <regex>
#include <stdlib.h>

using namespace std;

// solution 1
class Solution {
public:
  int integerBreak(int n) {
    if (n == 2) return 1;
    if (n == 3) return 2;

    int threes = n / 3;
    int left = n % 3;

    if (left == 1) {
      threes--;
      left = 4;
    }

    if (left > 0) return left * pow(3, threes);
    return pow(3, threes);
  }
};

// test
int main() {
  return 0;
}



