/*
 * https://leetcode.com/problems/house-robber/description/
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed, the only constraint stopping
 * you from robbing each of them is that adjacent houses have security system
 * connected and it will automatically contact the police if two adjacent
 * houses were broken into on the same night.
 *
 * Given a list of non-negative integers representing the amount of money of
 * each house, determine the maximum amount of money you can rob tonight without
 * alerting the police.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

// solution 1
class Solution {
public:
  int rob(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return nums[0];

    int prev = nums[0], cur = max(nums[0], nums[1]);
    for (int i = 2; i < nums.size(); i++) {
      int temp = cur;
      cur = max(cur, prev + nums[i]);
      prev = temp;
    }

    return cur;
  }
};


// test
int main() {
  ListNode* l1 = new ListNode(2);
  ListNode* l2 = new ListNode(1);

  Solution solution;
  solution.mergeTwoLists(l1, l2);
  return 0;
}


