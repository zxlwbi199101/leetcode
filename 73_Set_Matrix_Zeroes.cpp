/*
 * https://leetcode.com/problems/set-matrix-zeroes/description/
 *
 * Given a m x n matrix, if an element is 0, set its entire row and column
 * to 0. Do it in place.
 *
 * click to show follow up.
 *
 * Follow up:
 * Did you use extra space?
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best solution.
 * Could you devise a constant space solution?
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
  void setZeroes(vector<vector<int>>& matrix) {
    int height = matrix.size(), width = matrix[0].size();
    bool hasFound = false;
    bool hasFoundZeroInFirstCol = false;
    bool hasFoundZeroInFirstRow = false;

    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        if (!matrix[i][j]) {
          matrix[i][0] = matrix[-0][j] = 0;
          hasFound = true;

          if (i == 0) hasFoundZeroInFirstRow = true;
          if (j == 0) hasFoundZeroInFirstCol = true;
        }
      }
    }

    if (hasFound) {
      for (int i = 1; i < height; i++) {
        for (int j = 1; j < width; j++) {
          if (!matrix[i][0] || !matrix[0][j]) matrix[i][j] = 0;
        }

        if (hasFoundZeroInFirstCol) matrix[i][0] = 0;
      }

      if (hasFoundZeroInFirstRow) {
        for (int j = 1; j < width; j++) {
          matrix[0][j] = 0;
        }
      }
    }
  }
};


// test
int main() {
  Solution solution;

  vector<int> w1 = {0,0,0,5};
  vector<int> w2 = {4,3,1,4};
  vector<int> w3 = {0,1,1,4};
  vector<int> w4 = {1,2,1,3};
  vector<int> w5 = {0,0,1,1};
  vector<vector<int>> w = {w1,w2,w3,w4,w5};

  solution.setZeroes(w);
  for (vector<int> row : w) {
    for (int n : row) {
      cout << n << " ";
    }
    cout << endl;
  }

  return 0;
}

