/*
 * https://leetcode.com/problems/power-of-three/description/
 *
 * Given an integer, write a function to determine if it is a power of three.
 *
 * Follow up:
 * Could you do it without using any loop / recursion?
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
  bool isPowerOfThree(int n) {
    // int32 max 3^x is 1162261467
    return n > 0 && 1162261467 % n == 0;
  }
};

// test
int main() {
  Solution solution;
  cout << solution.isPowerOfThree(9) << endl;

  return 0;
}



