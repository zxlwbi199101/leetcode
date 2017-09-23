/*
 * https://leetcode.com/problems/search-a-2d-matrix/description/
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 *
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the
 * previous row.
 * For example,
 *
 * Consider the following matrix:
 *
 * [
 *   [1,   3,  5,  7],
 *   [10, 11, 16, 20],
 *   [23, 30, 34, 50]
 * ]
 * Given target = 3, return true.
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
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int height = matrix.size();
    if (!height) return false;
    int width = matrix[0].size();
    if (!width) return false;
    int len = width * height;

    int from = 0, end = len - 1;
    while (from <= end) {
      int middle = from + (end - from) / 2;
      int x = middle % width;
      int y = middle / width;

      if (from == end) return matrix[y][x] == target;

      if (matrix[y][x] == target) return true;
      else if (matrix[y][x] > target) end = middle - 1;
      else from = middle + 1;
    }

    return false;
  }
};


// test
int main() {
  Solution solution;

  // vector<int> w1 = {1,3,5,7};
  // vector<int> w2 = {8,10,11,12};
  // vector<int> w3 = {13,15,16,17};
  // vector<vector<int>> w = {w1,w2,w3};

  // cout << solution.searchMatrix(w, 3) << endl;


  vector<int> w1 = {1,1};
  vector<vector<int>> w = {w1};

  cout << solution.searchMatrix(w, 2) << endl;

  return 0;
}

