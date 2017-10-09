/*
 * https://leetcode.com/problems/sqrtx/description/
 *
 * Implement int sqrt(int x).
 *
 * Compute and return the square root of x.
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
  int mySqrt(int x) {
    long i = 0, j = x;

    while (i < j) {
      long mid = (i + j) / 2;
      long root = mid * mid;

      if (root == x) return mid;
      if (root < x) {
        i = mid + 1;
        if (i * i > x) return mid;
      } else {
        j = mid - 1;
      }
    }

    return i;
  }
};

// test
int main() {
  Solution solution;
  cout << solution.mySqrt(4) << endl;
  cout << solution.mySqrt(2147395599) << endl;
  cout << solution.mySqrt(2) << endl;

  return 0;
}



