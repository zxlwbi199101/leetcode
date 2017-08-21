/*
 * https://leetcode.com/problems/triangle/description/
 *
 * Given a triangle, find the minimum path sum from top to bottom.
 * Each step you may move to adjacent numbers on the row below.
 *
 * For example, given the following triangle
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

// solution 1
class Solution {
public:
  int minimumTotal(vector<vector<int>>& triangle) {
    for (int i = triangle.size() - 2; i >= 0; i--) {
      for (int j = 0; j <= i; j++) {
        triangle[i][j] = min(triangle[i + 1][j], triangle[i + 1][j + 1]) + triangle[i][j];
      }
    }

    return triangle[0][0];
  }
};

// test
int main() {
  Solution solution;

  vector<vector<int>> input;

  vector<int> nums1 = {2};
  vector<int> nums2 = {3,4};
  // vector<int> nums3 = {6,5,7};
  // vector<int> nums4 = {4,1,8,3};

  input.push_back(nums1);
  input.push_back(nums2);
  // input.push_back(nums3);
  // input.push_back(nums4);

  cout << solution.minimumTotal(input) << endl;

  return 0;
}


