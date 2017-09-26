/*
 * https://leetcode.com/problems/search-for-a-range/description/
 *
 * Given an array of integers sorted in ascending order, find the starting
 * and ending position of a given target value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * If the target is not found in the array, return [-1, -1].
 *
 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].
 *
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;


// solution 1
class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> result = {-1, -1};
    if (!nums.size()) return result;

    int start = 0, end = nums.size() - 1;
    while (start < end) {
      int mid = (start + end) / 2;
      if (nums[mid] >= target) end = mid;
      else start = mid + 1;
    }

    if (nums[start] != target) return result;
    result[0] = start;

    end = nums.size() - 1;
    while (start < end) {
      int mid = (start + end) / 2;
      if (nums[mid] <= target) start = mid + 1;
      else end = mid - 1;
    }

    result[1] = nums[start] == target ? start : (start - 1);
    return result;
  }
};

// test
int main() {
  Solution solution;

  vector<int> nums = {1,1};

  for (auto r : solution.searchRange(nums, 8)) {
    cout << r << " ";
  }

  return 0;
}


