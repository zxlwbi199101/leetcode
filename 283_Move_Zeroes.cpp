/*
 * https://leetcode.com/problems/move-zeroes/#/description
 *
 * Given an array nums, write a function to move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.
 *
 * For example, given nums = [0, 1, 0, 3, 12], after calling your function,
 * nums should be [1, 3, 12, 0, 0].
 *
 * Note:
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 *
 */

#include <iostream>
#include <vector>
#include <utility>
using namespace std;


// solution 1
class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    int nonZeroCount = 0;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != 0) {
        swap(nums[i], nums[nonZeroCount]);
        nonZeroCount++;
      }
    }
  }
};


// test
int main() {
  Solution solution;

  vector<int> nums = {0, 1, 0, 3, 12};
  solution.moveZeroes(nums);

  for (int i : nums) cout << i << ',';
  cout << endl;

  return 0;
}
