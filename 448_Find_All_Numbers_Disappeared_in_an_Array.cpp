/*
 * https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/#/solutions
 *
 * Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array),
 * some elements appear twice and others appear once.
 * Find all the elements of [1, n] inclusive that do not appear in this array.
 * Could you do it without extra space and in O(n) runtime? You may assume the
 * returned list does not count as extra space.
 *
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;


// solution 1
class Solution {
public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    for (int n : nums) {
      int index = (n > 0 ? 1 : -1) * n - 1;
      nums[index] *= nums[index] > 0 ? -1 : 1;
    }

    vector<int> result;
    for (int i = 0, size = nums.size(); i < size; i++) {
      if (nums[i] > 0) {
        result.push_back(i + 1);
      }
    }

    return result;
  }
};


// test
int main() {
  Solution solution;

  vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
  vector<int> result = solution.findDisappearedNumbers(nums);

  for (int n : result) {
    cout << n << endl;
  }

  return 0;
}


