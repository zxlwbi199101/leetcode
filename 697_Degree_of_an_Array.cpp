/*
 * https://leetcode.com/problems/degree-of-an-array/description/
 *
 * Given a non-empty array of non-negative integers nums, the degree of this
 * array is defined as the maximum frequency of any one of its elements.
 *
 * Your task is to find the smallest possible length of a (contiguous) subarray
 * of nums, that has the same degree as nums.
 *
 * Example 1:
 * Input: [1, 2, 2, 3, 1]
 * Output: 2
 * Explanation:
 * The input array has a degree of 2 because both elements 1 and 2 appear twice.
 * Of the subarrays that have the same degree:
 * [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
 * The shortest length is 2. So return 2.
 * Example 2:
 * Input: [1,2,2,3,1,4,2]
 * Output: 6
 * Note:
 *
 * nums.length will be between 1 and 50,000.
 * nums[i] will be an integer between 0 and 49,999.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

// solution 1
class Solution {
public:
  int findShortestSubArray(vector<int>& nums) {
    if (!nums.size()) return 0;
    unordered_map<int, vector<int>> m;
    int maxLen = 1;

    for (int i = 0; i < nums.size(); i++) {
      auto it = m.find(nums[i]);
      if (it == m.end()) {
        vector<int> t = {1, i, i};
        m[nums[i]] = t;
      } else {
        (it->second)[2] = i;
        (it->second)[0]++;
        maxLen = max(maxLen, (it->second)[0]);
      }
    }

    int minLen = INT_MAX;
    for (auto it = m.begin(); it != m.end(); it++) {
      if ((it->second)[0] == maxLen) {
        minLen = min(minLen, (it->second)[2] - (it->second)[1]);
      }
    }

    return minLen + 1;
  }
};

// test
int main() {
  Solution solution;

  vector<int> nums = {1,2,2,3,1,4,2};
  cout << solution.findShortestSubArray(nums) << endl;

  return 0;
}


