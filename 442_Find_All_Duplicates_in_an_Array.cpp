/*
 * https://leetcode.com/problems/find-all-duplicates-in-an-array/description/
 *
 * Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some
 * elements appear twice and others appear once.
 *
 * Find all the elements that appear twice in this array.
 *
 * Could you do it without extra space and in O(n) runtime?
 *
 * Example:
 * Input:
 * [4,3,2,7,8,2,3,1]
 *
 * Output:
 * [2,3]
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <math.h>
using namespace std;

// solution 1
class Solution {
public:
  vector<int> findDuplicates(vector<int>& nums) {
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
      int index = abs(nums[i]) - 1;
      if (nums[index] < 0) result.push_back(abs(nums[i]));
      else nums[index] *= -1;
    }

    return result;
  }
};

// test
int main() {
  Solution solution;

  vector<int> nums = {4,3,2,7,8,2,3,1};
  for (int i : solution.findDuplicates(nums)) cout << i << endl;

  return 0;
}


