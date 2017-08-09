/*
 * https://leetcode.com/problems/maximum-average-subarray-i/description/
 *
 * Given an array consisting of n integers, find the contiguous subarray of given
 * length k that has the maximum average value. And you need to output the maximum
 * average value.
 *
 */

#include <iostream>
#include <vector>
#include <set>
using namespace std;

// solution 1
class Solution {
public:
  double findMaxAverage(vector<int>& nums, int k) {
    double sum = 0;
    double maxVal = INT_MIN;

    for (int i = 0; i < nums.size(); i++) {
      if (i < k) {
        sum += nums[i];
        if (i == k - 1) maxVal = sum;
      } else {
        sum += nums[i] - nums[i - k];
        maxVal = max(sum, maxVal);
      }
    }

    return maxVal / k;
  }
};


// test
int main() {
  Solution solution;

  vector<int> nums1 = {9,7,3,5,6,2,0,8,1,9};
  vector<int> nums2 = {1};

  cout << solution.findMaxAverage(nums1, 6) << endl;
  cout << solution.findMaxAverage(nums2, 1) << endl;
  return 0;
}


