/*
 * https://leetcode.com/problems/product-of-array-except-self/description/
 *
 * Given an array of n integers where n > 1, nums, return an array output such
 * that output[i] is equal to the product of all the elements of nums except
 * nums[i].
 *
 * Solve it without division and in O(n).
 *
 * For example, given [1,2,3,4], return [24,12,8,6].
 *
 * Follow up:
 * Could you solve it with constant space complexity? (Note: The output array
 * does not count as extra space for the purpose of space complexity analysis.)
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
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> result (nums.size());
    result[0] = 1;

    int temp = 1;

    for (int i = 1; i < nums.size(); i++) {
      result[i] = result[i - 1] * nums[i - 1];
    }

    for (int i = nums.size() - 1; i > 0; i--) {
      temp *= nums[i];
      result[i - 1] *= temp;
    }
    return result;
  }
};

// test
int main() {
  Solution solution;

  vector<int> nums = {1,2,3,4};
  vector<int> result = solution.productExceptSelf(nums);

  for (int n : result) cout << n << endl;

  return 0;
}


