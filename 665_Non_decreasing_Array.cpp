/*
 * https://leetcode.com/problems/non-decreasing-array/description/
 *
 * Given an array with n integers, your task is to check if it could become
 * non-decreasing by modifying at most 1 element.
 *
 * We define an array is non-decreasing if array[i] <= array[i + 1] holds for
 * every i (1 <= i < n).
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
  bool checkPossibility(vector<int>& nums) {
    if (!nums.size()) return true;

    bool bigger = false;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] < nums[i - 1]) {
        if (bigger) return false;

        bigger = true;
        if (i > 1 && nums[i] < nums[i - 2]) {
          nums[i] = nums[i - 1];
        } else {
          nums[i - 1] = nums[i];
        }
      }
    }

    return true;
  }
};

// test
int main() {
  Solution solution;

  vector<int> nums = {3,4,2,3};
  cout << solution.checkPossibility(nums) << endl;

  return 0;
}


