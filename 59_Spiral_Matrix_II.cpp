/*
 * https://leetcode.com/problems/spiral-matrix-ii/description/
 *
 * Given an integer n, generate a square matrix filled with elements
 * from 1 to n2 in spiral order.
 *
 * For example,
 * Given n = 3,
 *
 * You should return the following matrix:
 * [
 *  [ 1, 2, 3 ],
 *  [ 8, 9, 4 ],
 *  [ 7, 6, 5 ]
 * ]
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
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> result(n, vector<int>(n));

    for (int i = 1, len = n * n, c = 0; i <= len; c++) {
      // top, right, bottom, left
      for (int j = c; j < n - c && i <= len; j++) result[c][j] = i++;
      for (int j = c + 1; j < n - c - 1 && i <= len; j++) result[j][n - c - 1] = i++;
      for (int j = n - c - 1; j > c && i <= len; j--) result[n - c - 1][j] = i++;
      for (int j = n - c - 1; j > c && i <= len; j--) result[j][c] = i++;
    }

    return result;
  }
};


// test
int main() {
  Solution solution;

  for (vector<int> row : solution.generateMatrix(1)) {
    for (int r : row) cout << r << " ";
    cout << endl;
  }

  return 0;
}

