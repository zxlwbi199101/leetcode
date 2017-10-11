/*
 * https://leetcode.com/problems/nth-digit/
 *
 * Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8,
 * 9, 10, 11, ...
 *
 * Note:
 * n is positive and will fit within the range of a 32-bit signed integer
 * (n < 231).
 *
 * Example 1:
 *
 * Input:
 * 3
 *
 * Output:
 * 3
 * Example 2:
 *
 * Input:
 * 11
 *
 * Output:
 * 0
 *
 * Explanation:
 * The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0,
 * which is part of the number 10.
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
using namespace std;

// solution 1
class Solution {
public:
  int findNthDigit(int n) {
    long base = 1, level = 1, count = 0;
    while (count < n) {
      count += base * 9 * level;
      base *= 10;
      level++;
    }

    int minus = (count - n + level - 1) / (level - 1);
    int num = base - minus;

    int result = 0;
    for (int i = count - minus * (level - 1); i < n; i++) {
      result = num / (base / 10);
      base /= 10;
      num %= base;
    }

    return result;
  }
};

// test
int main() {
  Solution solution;
  cout << solution.findNthDigit(11) << endl;

  return 0;
}



