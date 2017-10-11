/*
 * https://leetcode.com/problems/factorial-trailing-zeroes/description/
 *
 * Given an integer n, return the number of trailing zeroes in n!.
 *
 * Note: Your solution should be in logarithmic time complexity.
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
  int trailingZeroes(int n) {
    int result = 0;

    while (n / 5 > 0) {
      n /= 5;
      result += n;
    }

    return result;
  }
};

// test
int main() {
  Solution solution;
  cout << solution.trailingZeroes(7) << endl;
  cout << solution.trailingZeroes(20) << endl;
  cout << solution.trailingZeroes(25) << endl;
  cout << solution.trailingZeroes(30) << endl;
  cout << solution.trailingZeroes(100) << endl;

  return 0;
}



