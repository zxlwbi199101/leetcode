/*
 * https://leetcode.com/problems/find-peak-element/description/
 *
 * A peak element is an element that is greater than its neighbors.
 * Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
 *
 * The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
 * You may imagine that num[-1] = num[n] = -∞.
 * For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
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
  int findPeakElement(vector<int>& nums) {
    int len = nums.size();

    for (int i = 0; i < len; i++) {
      if ((i == 0 || nums[i - 1] < nums[i]) && (i == len - 1 || nums[i + 1] < nums[i])) {
        return i;
      }
    }

    return 0;
  }
};

// test
int main() {
  Solution solution;

  vector<int> nums = {1, 2, 3, 1};
  cout << solution.findPeakElement(nums) << endl;

  return 0;
}


