/*
 * https://leetcode.com/problems/count-numbers-with-unique-digits/description/
 *
 * Given a non-negative integer n, count all numbers with unique digits, x,
 * where 0 ≤ x < 10n.
 *
 * Example:
 * Given n = 2, return 91. (The answer should be the total numbers in the range
 * of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])
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
  int countNumbersWithUniqueDigits(int n) {
    if (!n) return 1;
    int result = 10, others = 9;

    for (int i = 9; i > (10 - n) ; i--) {
      others *= i;
      result += others;
    }

    return result;
  }
};

// test
int main() {
  return 0;
}



