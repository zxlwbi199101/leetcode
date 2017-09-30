/*
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * Given n non-negative integers a1, a2, ..., an, where each represents
 * a point at coordinate (i, ai). n vertical lines are drawn such that the
 * two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which
 * together with x-axis forms a container, such that the container contains
 * the most water.
 *
 * Note: You may not slant the container and n is at least 2.
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
  int maxArea(vector<int>& height) {
    int maxArea = 0;
    int i = 0, j = height.size() - 1;

    while (i < j) {
      int area = min(height[j], height[i]) * (j - i);
      maxArea = max(area, maxArea);

      if (height[i] < height[j]) i++;
      else j--;
    }

    return maxArea;
  }
};
// 1 2 3 4 5 6 7
// test
int main() {
  Solution solution;

  vector<int> nums = {1, 3, 1, 2, 1, 4};
  cout << solution.maxArea(nums) << endl;

  return 0;
}


