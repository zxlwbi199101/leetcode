/*
 * https://leetcode.com/problems/range-addition-ii/#/description
 *
 * Given an m * n matrix M initialized with all 0's and several update operations.
 *
 * Operations are represented by a 2D array, and each operation is represented by an
 * array with two positive integers a and b, which means M[i][j] should be added by one
 * for all 0 <= i < a and 0 <= j < b.
 *
 * You need to count and return the number of maximum integers in the matrix after
 * performing all the operations.
 *
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// solution 1
class Solution {
public:
  int maxCount(int m, int n, vector<vector<int>>& ops) {
    if (ops.size() == 0) return m * n;

    int minR = INT_MAX;
    int minC = INT_MAX;

    for (vector<int> row : ops) {
      minR = min(minR, row[0]);
      minC = min(minC, row[1]);
    }

    return minR * minC;
  }
};


// test
int main() {
  Solution solution;

  vector<vector<int>> ops;
  vector<int> a = {2, 2};
  vector<int> b = {3, 3};
  ops.push_back(a);
  ops.push_back(b);

  cout << solution.maxCount(3, 3, ops) << endl;

  return 0;
}


