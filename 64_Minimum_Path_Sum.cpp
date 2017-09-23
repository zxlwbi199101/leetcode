/*
 * https://leetcode.com/problems/minimum-path-sum/description/
 *
 * Given a m x n grid filled with non-negative numbers, find a path
 * from top left to bottom right which minimizes the sum of all numbers
 * along its path.
 *
 * Note: You can only move either down or right at any point in time.
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
  int minPathSum(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (i > 0 && j > 0) {
          grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
        } else if (i > 0) {
          grid[i][0] += grid[i - 1][0];
        } else if (j > 0) {
          grid[0][j] += grid[0][j - 1];
        }
      }
    }

    return grid[rows - 1][cols - 1];
  }

  // int minPathSum(vector<vector<int>>& grid) {
  //   return check(grid, 0, 0, 0);
  // }

  // int check(vector<vector<int>>& grid, int row, int col, int sum) {
  //   int rows = grid.size();
  //   int cols = grid[0].size();

  //   if (row == rows - 1 && col == cols - 1) {
  //     return sum + grid[row][col];
  //   }

  //   int right = INT_MAX, bottom = INT_MAX;
  //   if (row < rows - 1) {
  //     bottom = check(grid, row + 1, col, sum + grid[row][col]);
  //   }
  //   if (col < cols - 1) {
  //     right = check(grid, row, col + 1, sum + grid[row][col]);
  //   }

  //   return min(right, bottom);
  // }
};


// test
int main() {
  Solution solution;

  vector<vector<int>> w = {
    {0,0,0,5},
    {4,3,1,4},
    {0,1,1,4},
    {1,2,1,3},
    {0,0,1,1}
  };
  cout << solution.minPathSum(w) << endl;

  // vector<vector<int>> w = {6,5,3,3,7,9,6,8,1,4,8,3},
  // {7,6,6,9,8,6,7,5,3,0,9,8},
  // {7,0,6,9,9,0,3,7,7,9,1,7},
  // {8,9,5,2,3,5,5,2,2,2,3,2},
  // {0,0,8,5,0,9,6,8,0,2,9,9},
  // {2,4,7,2,5,0,9,4,9,6,8,4},
  // {2,3,6,6,7,0,8,0,0,6,7,3},
  // {6,3,3,8,6,2,7,0,8,6,2,4},
  // {6,1,0,7,0,8,1,2,3,0,0,1},
  // {0,0,1,2,9,0,5,5,4,8,5,0},
  // {2,2,2,1,1,5,7,9,8,7,7,8},
  // {5,0,2,8,0,4,1,2,5,4,7,4},
  // {5,2,1,9,3,6,1,5,0,3,8,1}};
  // cout << solution.minPathSum(w) << endl;

  return 0;
}

