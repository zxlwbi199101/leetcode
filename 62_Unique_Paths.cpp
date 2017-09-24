/*
 * https://leetcode.com/problems/unique-paths/discuss/
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start'
 * in the diagram below).
 *
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 *
 * How many possible unique paths are there?
 *
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;


// solution 1
class Solution {
public:
  int uniquePaths(int m, int n) {
    // select different go down from all steps
    long sum = 1;

    // C(m-1)(m+n-2)
    // (m+n-2)! / (m-1)!(n-1)!
    for (int i = 0; i < min(m - 1, n - 1); i++) {
      sum = sum * (m + n - 2 - i) / (i + 1);
    }

    return sum;
  }
};


// test
int main() {
  Solution solution;

  cout << solution.uniquePaths(10, 10) << endl;

  return 0;
}

