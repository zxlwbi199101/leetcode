/*
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * Find the minimum element.
 * You may assume no duplicate exists in the array.
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
  int findMin(vector<int>& nums) {
    if (!nums.size()) return 0;

    int last = nums[0];

    for (int n : nums) {
      if (last > n) {
        return n;
      }
    }

    return last;
  }
};

// test
int main() {
  Solution solution;

  vector<int> nums = {0,1,2,4,5,6,7};
  cout << solution.findMin(nums) << endl;

  return 0;
}


