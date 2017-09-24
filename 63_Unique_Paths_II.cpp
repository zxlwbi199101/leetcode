/*
 * https://leetcode.com/problems/unique-paths-ii/description/
 *
 * Follow up for "Unique Paths":
 *
 * Now consider if some obstacles are added to the grids. How many unique
 * paths would there be?
 *
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 *
 * For example,
 * There is one obstacle in the middle of a 3x3 grid as illustrated below.
 *
 * [
 *   [0,0,0],
 *   [0,1,0],
 *   [0,0,0]
 * ]
 * The total number of unique paths is 2.
 *
 * Note: m and n will be at most 100.
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
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int rows = obstacleGrid.size();
    int cols = obstacleGrid[0].size();

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (obstacleGrid[i][j]) {
          obstacleGrid[i][j] = 0;
        } else {
          if (i > 0) obstacleGrid[i][j] += obstacleGrid[i - 1][j];
          if (j > 0) obstacleGrid[i][j] += obstacleGrid[i][j - 1];

          if (!i && !j) obstacleGrid[i][j] = 1;
        }
      }
    }

    return obstacleGrid[rows - 1][cols - 1];
  }
};


// test
int main() {
  Solution solution;

  vector<vector<int>> w = {
    {0,0,0,0},
    {0,1,0,0},
    {0,0,0,0}
  };
  cout << solution.uniquePathsWithObstacles(w) << endl;

  return 0;
}

