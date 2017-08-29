/*
 * https://leetcode.com/problems/rotate-image/description/
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
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
  void rotate(vector<vector<int>>& matrix) {
    int width = matrix.size();
    int temp = 0;

    for (int i = 0; i < (width + 1) / 2; i++) {
      for (int j = 0; j < width / 2; j++) {
        temp = matrix[i][j];

        matrix[i][j] = matrix[width - j - 1][i]; // left top
        matrix[width - j - 1][i] = matrix[width - i - 1][width - j - 1]; // left bottom
        matrix[width - i - 1][width - j - 1] = matrix[j][width - i - 1]; // right bottom
        matrix[j][width - i - 1] = temp; // right top
      }
    }
  }
};

// test
int main() {
  Solution solution;

  vector<int> nums1 = {1,2,3};
  vector<int> nums2 = {4,5,6};
  vector<int> nums3 = {7,8,9};
  vector<vector<int>> matrix = {nums1, nums2, nums3};

  solution.rotate(matrix);
  cout << matrix[0][0] << endl;

  return 0;
}


