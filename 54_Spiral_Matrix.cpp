/*
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements
 * of the matrix in spiral order.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// solution 1
class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if (!matrix.size() || !matrix[0].size()) {
      return vector<int>(0);
    }

    int n = matrix.size();
    int m = matrix[0].size();
    int len = m * n;

    vector<int> result (len);

    for (int i = 0, pile = 0; i < len; pile++) {
      // iterate 4 side of a square
      // top
      for (int j = pile; j < m - pile && i < len; j++) {
        result[i++] = matrix[pile][j];
      }
      // right
      for (int j = pile + 1; j < n - pile - 1 && i < len; j++) {
        result[i++] = matrix[j][m - pile - 1];
      }
      // bottom
      for (int j = m - pile - 1; j > pile && i < len; j--) {
        result[i++] = matrix[n - pile - 1][j];
      }
      // left
      for (int j = n - pile - 1; j > pile && i < len; j--) {
        result[i++] = matrix[j][pile];
      }
    }

    return result;
  }
};

// test
int main() {
  Solution solution;

  vector<int> nums1 = {1,2,3};
  vector<int> nums2 = {4,5,6};
  vector<int> nums3 = {7,8,9};
  vector<vector<int>> matrix = {nums1, nums2, nums3};

  vector<int> result = solution.spiralOrder(matrix);
  for (int i : result) {
    cout << i << endl;
  }
  return 0;
}


