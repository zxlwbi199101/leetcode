/*
 * https://leetcode.com/problems/power-of-two/description/
 *
 * Given an integer, write a function to determine if it is a power of two.
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
  // bool isPowerOfTwo(int n) {
  //   for (int i = 1; i <= n; i <<= 1) {
  //     if (i == n) return true;
  //     if (i > INT_MAX >> 1) return false;
  //   }
  //   return false;
  // }
  // bool isPowerOfTwo(int n) {
  //   while (n > 1) {
  //     if (n % 2) return false;
  //     if (n == 2) return true;
  //     n >>= 1;
  //   }
  //   return false;
  // }
  bool isPowerOfTwo(int n) {
    return n > 0 && 2147483648 % n == 0;
  }
};

// test
int main() {
  Solution solution;
  cout << solution.isPowerOfTwo(1073741825) << endl;

  return 0;
}



