/*
 * https://leetcode.com/problems/happy-number/description/
 *
 * Write an algorithm to determine if a number is "happy".
 *
 * A happy number is a number defined by the following process: Starting with
 * any positive integer, replace the number by the sum of the squares of its
 * digits, and repeat the process until the number equals 1 (where it will stay),
 * or it loops endlessly in a cycle which does not include 1. Those numbers for
 * which this process ends in 1 are happy numbers.
 *
 * Example: 19 is a happy number
 *
 * 12 + 92 = 82
 * 82 + 22 = 68
 * 62 + 82 = 100
 * 12 + 02 + 02 = 1
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
  bool isHappy(int n) {
    set<int> s;

    while (n != 1) {
      int tmp = 0;

      while (n > 0) {
        tmp += (n % 10) * (n % 10);
        n /= 10;
      }

      n = tmp;
      if (s.find(n) != s.end()) return false;
      s.insert(n);
    }

    return true;
  }
};

// test
int main() {
  Solution solution;
  cout << solution.isHappy(7) << endl;

  return 0;
}



