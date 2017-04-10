/*
 * https://leetcode.com/problems/add-digits/#/description
 *
 * Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
 *
 * For example:
 * Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
 *
 * Could you do it without any loop/recursion in O(1) runtime?
 *
 */

#include <iostream>
#include <string>
#include <queue>
using namespace std;

// 12,345 = 1 × (9,999 + 1) + 2 × (999 + 1) + 3 × (99 + 1) + 4 × (9 + 1) + 5
// 12,345 = (1 × 9,999 + 2 × 999 + 3 × 99 + 4 × 9) + (1 + 2 + 3 + 4 + 5)
// so should be "% 9"

// solution 1
class Solution {
public:
  int addDigits(int num) {
    return (num - 1) % 9 + 1;
  }
};


// test
int main() {
  Solution solution;

  cout << solution.addDigits(12345) << endl;

  return 0;
}


