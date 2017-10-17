/*
 * https://leetcode.com/problems/range-sum-query-immutable/description/
 *
 * Given an integer array nums, find the sum of the elements between indices i
 * and j (i ≤ j), inclusive.
 *
 * Example:
 * Given nums = [-2, 0, 3, -5, 2, -1]
 *
 * sumRange(0, 2) -> 1
 * sumRange(2, 5) -> -1
 * sumRange(0, 5) -> -3
 * Note:
 * You may assume that the array does not change.
 * There are many calls to sumRange function.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

class NumArray {
public:
  vector<int> cache;

  NumArray(vector<int> nums) {
    for (int i = 1; i < nums.size(); i++) {
      nums[i] += nums[i - 1];
    }
    cache = nums;
  }

  int sumRange(int i, int j) {
    if (i == 0) return cache[j];
    return cache[j] - cache[i - 1];
  }
};

// test
int main() {
  Solution solution;
  return 0;
}


