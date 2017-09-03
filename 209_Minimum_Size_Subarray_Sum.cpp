/*
 * https://leetcode.com/problems/minimum-size-subarray-sum/description/
 *
 * Given an array of n positive integers and a positive integer s, find the minimal length
 * of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.
 *
 * For example, given the array [2,3,1,2,4,3] and s = 7,
 * the subarray [4,3] has the minimal length under the problem constraint.
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
  // int minSubArrayLen(int s, vector<int>& nums) {
  //   int minLen = INT_MAX;
  //   int sum = 0;
  //   int i = 0;
  //   int j = 0;

  //   for (i = 0; i < nums.size(); i++) {
  //     for (j = i, sum = 0; j < nums.size() && sum < s; j++) {
  //       sum += nums[j];
  //     }

  //     if (sum >= s) {
  //       minLen = min(minLen, j - i);
  //     }
  //   }

  //   return minLen == INT_MAX ? 0 : minLen;
  // }

  // O(n)
  int minSubArrayLen(int s, vector<int>& nums) {
    int minLen = INT_MAX;
    int sum = 0;
    int pointer = 0;

    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];

      while (sum >= s) {
        sum -= nums[pointer++];
        if (sum < s) {
          minLen = min(minLen, i - pointer + 2);
        }
      }
    }

    return minLen == INT_MAX ? 0 : minLen;
  }
};

// test
int main() {
  Solution solution;

  vector<int> nums = {2,3,1,2,4,3};
  cout << solution.minSubArrayLen(7, nums) << endl;

  return 0;
}


