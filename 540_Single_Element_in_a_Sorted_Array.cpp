/*
 * https://leetcode.com/problems/single-element-in-a-sorted-array/description/
 *
 * Given a sorted array consisting of only integers where every element
 * appears twice except for one element which appears once. Find this single
 * element that appears only once.
 *
 * Example 1:
 * Input: [1,1,2,3,3,4,4,8,8]
 * Output: 2
 * Example 2:
 * Input: [3,3,7,7,10,11,11]
 * Output: 10
 * Note: Your solution should run in O(log n) time and O(1) space.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <list>
#include <queue>
#include <math.h>
#include <ctype.h>
using namespace std;

// solution 1
class Solution {
public:
  int singleNonDuplicate(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return nums[0];

    int result = 0;
    int left = 0, right = nums.size() - 1;

    while (left < right) {
      int mid = left + (right - left) / 2;

      if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]) {
        return nums[mid];
      }

      if (mid % 2) {
        if (nums[mid] == nums[mid - 1]) left = mid + 1;
        else right = mid - 1;
      } else {
        if (nums[mid] == nums[mid + 1]) left = mid + 1;
        else right = mid - 1;
      }
    }

    return nums[left];
  }
};


// test case
int main() {
  return 0;
}
