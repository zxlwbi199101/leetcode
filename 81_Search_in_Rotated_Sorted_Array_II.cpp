/*
 * https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
 *
 * Follow up for "Search in Rotated Sorted Array":
 * What if duplicates are allowed?
 *
 * Would this affect the run-time complexity? How and why?
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * Write a function to determine if a given target is in the array.
 *
 * The array may contain duplicates.
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
  bool search(vector<int>& nums, int target) {
    int start = 0, end = nums.size() - 1;

    while (start <= end) {
      int mid = (end + start) / 2;
      if (nums[mid] == target || nums[end] == target || nums[start] == target) return true;

      if (nums[mid] > nums[end]) {
        if (target > nums[mid] || target < nums[end]) start = mid + 1;
        else end = mid - 1;
      } else if (nums[mid] < nums[end]) {
        if (nums[end] > target && nums[mid] < target) start = mid + 1;
        else end = mid - 1;
      } else {
        end--;
      }
    }

    return false;
  }
};

// test
int main() {
  Solution solution;

  vector<int> nums = {-9,-9,-9,-8,-8,-7,-7,-7,-7,-6,-6,-6,-6,-6,-6,-6,-6,-6,-5,-5,-5,-5,-5,-4,-4,-4,-3,-3,-3,-3,-3,-3,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-1,-1,-1,-1,-1,-1,0,0,0,1,1,2,2,2,2,2,2,2,3,3,3,3,4,4,4,4,4,5,5,5,5,5,5,5,6,6,6,7,7,7,7,7,8,9,9,9,10,10,10,10,10,10,10,-10,-9,-9,-9,-9
    };

  cout << solution.search(nums, 2) << endl;

  return 0;
}


