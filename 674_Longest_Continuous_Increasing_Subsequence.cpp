/*
 * https://leetcode.com/problems/triangle/description/
 *
 * Given an unsorted array of integers, find the length of longest continuous
 * increasing subsequence.
 *
 * Example 1:
 * Input: [1,3,5,4,7]
 * Output: 3
 * Explanation: The longest continuous increasing subsequence is [1,3,5],
 * its length is 3.
 * Even though [1,3,5,7] is also an increasing subsequence, it's not a
 * continuous one where 5 and 7 are separated by 4.
 *
 * Example 2:
 * Input: [2,2,2,2,2]
 * Output: 1
 * Explanation: The longest continuous increasing subsequence is [2], its
 * length is 1.
 * Note: Length of the array will not exceed 10,000.
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
  int findLengthOfLCIS(vector<int>& nums) {
    int maxLen = 0;
    int len = 0;
    int last = INT_MIN;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] <= last) len = 0;

      last = nums[i];
      maxLen = max(maxLen, ++len);
    }

    return maxLen;
  }
};

// test
int main() {
  Solution solution;

  vector<int> nums = {2,1,3};
  cout << solution.findLengthOfLCIS(nums) << endl;

  return 0;
}


