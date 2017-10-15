/*
 * https://leetcode.com/problems/max-area-of-island/description/
 *
 * Given a non-empty 2D array grid of 0's and 1's, an island is a group of
 * 1's (representing land) connected 4-directionally (horizontal or vertical.)
 * You may assume all four edges of the grid are surrounded by water.
 *
 * Find the maximum area of an island in the given 2D array. (If there is no
 * island, the maximum area is 0.)
 *
 * Example 1:
 * [[0,0,1,0,0,0,0,1,0,0,0,0,0],
 *  [0,0,0,0,0,0,0,1,1,1,0,0,0],
 *  [0,1,1,0,1,0,0,0,0,0,0,0,0],
 *  [0,1,0,0,1,1,0,0,1,0,1,0,0],
 *  [0,1,0,0,1,1,0,0,1,1,1,0,0],
 *  [0,0,0,0,0,0,0,0,0,0,1,0,0],
 *  [0,0,0,0,0,0,0,1,1,1,0,0,0],
 *  [0,0,0,0,0,0,0,1,1,0,0,0,0]]
 * Given the above grid, return 6. Note the answer is not 11, because the
 * island must be connected 4-directionally.
 * Example 2:
 * [[0,0,0,0,0,0,0,0]]
 * Given the above grid, return 0.
 * Note: The length of each dimension in the given grid does not exceed 50.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

// solution 1
class Solution {
public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    if (!grid.size()) return 0;
    int maxSum = INT_MIN;

    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] <= 0) continue;
        maxSum = max(maxSum, scan(grid, i, j, 0));
      }
    }

    return maxSum == INT_MIN ? 0 : maxSum;
  }

  int scan(vector<vector<int>>& grid, int i, int j, int sum) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()
      || grid[i][j] <= 0) return sum;

    grid[i][j] = -1;
    sum += scan(grid, i - 1, j, 0) + scan(grid, i + 1, j, 0)
      + scan(grid, i, j - 1, 0) + scan(grid, i, j + 1) + 1;

    return sum;
  }
};
// 1 2 3 4 5 6 7
// test
int main() {
  Solution solution;

  return 0;
}


