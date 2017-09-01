/*
 * https://leetcode.com/problems/jump-game/description/
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 *
 * Each element in the array represents your maximum jump length at that position.
 * Determine if you are able to reach the last index.
 *
 * For example:
 * A = [2,3,1,1,4], return true.
 * A = [3,2,1,0,4], return false.
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
  bool canJump(vector<int>& nums) {
    if (!nums.size()) return true;

    int lastIndex = nums[nums.size() - 1];
    for (int i = nums.size() - 1; i >= 0; i--) {
      if (nums[i] + i >= lastIndex) {
        lastIndex = i;
      }
    }

    return lastIndex == 0;
  }
};

// test
int main() {
  Solution solution;

  vector<int> nums = {3,2,1,0,4};
  cout << solution.canJump(nums) << endl;

  return 0;
}


