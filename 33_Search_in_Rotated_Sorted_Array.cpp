/*
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * Suppose an array sorted in ascending order is rotated at some pivot
 * unknown to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 *
 * You may assume no duplicate exists in the array.
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
  int search(vector<int>& nums, int target) {
    if (!nums.size()) return -1;
    int start = 0, end = nums.size() - 1;

    while (start < end) {
      int mid = (start + end) / 2;
      if (nums[mid] == target) return mid;

      // left part is ordered
      if (nums[mid] >= nums[start]) {
        if (target < nums[mid] && target >= nums[start]) end = mid - 1;
        else start = mid + 1;
      // right part is ordered
      } else if (target > nums[mid] && target <= nums[end]) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }

    return nums[start] == target ? start : -1;
  }
};

// test
int main() {
  Solution solution;
  // 1 2 3 4 5 6 7
  // 3 4 5 6 7 1 2

  // 6 7 1 2 3 4 5
  vector<int> nums = {8,9,2,3,4};
  cout << solution.search(nums, 9) << endl;

  return 0;
}


