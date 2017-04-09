/*
 * https://leetcode.com/problems/island-perimeter/#/description
 *
 * You are given a map in form of a two-dimensional integer grid
 * where 1 represents land and 0 represents water. Grid cells are
 * connected horizontally/vertically (not diagonally).
 * The grid is completely surrounded by water, and there is exactly
 * one island (i.e., one or more connected land cells).
 * The island doesn't have "lakes" (water inside that isn't connected to
 * the water around the island). One cell is a square with side length 1.
 * The grid is rectangular, width and height don't exceed 100. Determine the
 * perimeter of the island.
 *
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;


// solution 1
class Solution {
public:
  int islandPerimeter(vector<vector<int>>& grid) {
    int islandCell = 0;
    int neibours = 0;

    for (int i = 0; i < grid.size(); i++) {
      vector<int> row = grid[i];
      for (int j = 0; j < row.size(); j++) {
        if (row[j] == 0) continue;

        islandCell++;
        if (i > 0 && grid[i - 1][j] == 1) neibours++;
        if (j > 0 && grid[i][j - 1] == 1) neibours++;
      }
    }

    return islandCell * 4 - neibours * 2;
  }
};


// test
int main() {
  Solution solution;

  vector<vector<int>> grid = {
    {0,1,0,0},
    {1,1,1,0},
    {0,1,0,0},
    {1,1,0,0}
  };

  cout << solution.islandPerimeter(grid) << endl;

  return 0;
}


