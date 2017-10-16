/*
 * https://leetcode.com/problems/climbing-stairs/description/
 *
 * You are climbing a stair case. It takes n steps to reach to the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 *
 * Note: Given n will be a positive integer.
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
  int climbStairs(int n) {
    int cur = 0, cur2 = 1, temp = 0;

    for (int i = 0; i < n; i++) {
      temp = cur2;
      cur2 += cur;
      cur = temp;
    }

    return cur2;
  }
};

// test
int main() {
  Solution solution;
  cout << solution.climbStairs(5) << endl;

  return 0;
}



