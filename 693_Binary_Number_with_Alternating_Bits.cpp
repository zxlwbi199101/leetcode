/*
 * https://leetcode.com/problems/binary-number-with-alternating-bits/description/
 *
 * Given a positive integer, check whether it has alternating bits: namely, if
 * two adjacent bits will always have different values.
 *
 * Example 1:
 * Input: 5
 * Output: True
 * Explanation:
 * The binary representation of 5 is: 101
 * Example 2:
 * Input: 7
 * Output: False
 * Explanation:
 * The binary representation of 7 is: 111.
 * Example 3:
 * Input: 11
 * Output: False
 * Explanation:
 * The binary representation of 11 is: 1011.
 * Example 4:
 * Input: 10
 * Output: True
 * Explanation:
 * The binary representation of 10 is: 1010.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

// solution 1
class Solution {
public:
  bool hasAlternatingBits(int n) {
    int last = n % 2;
    n /= 2;

    while (n > 0) {
      if (last == n % 2) {
        return false;
      }
      last = n % 2;
      n /= 2;
    }

    return true;
  }
};

// test
int main() {
  Solution solution;

  cout << solution.hasAlternatingBits(5) << endl;

  return 0;
}


