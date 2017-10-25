/*
 * https://leetcode.com/problems/next-greater-element-ii/description/
 *
 * Given a circular array (the next element of the last element is the first
 * element of the array), print the Next Greater Number for every element.
 * The Next Greater Number of a number x is the first greater number to its
 * traversing-order next in the array, which means you could search circularly
 * to find its next greater number. If it doesn't exist, output -1 for this number.
 *
 * Example 1:
 * Input: [1,2,1]
 * Output: [2,-1,2]
 * Explanation: The first 1's next greater number is 2;
 * The number 2 can't find next greater number;
 * The second 1's next greater number needs to search circularly, which is also 2.
 * Note: The length of given array won't exceed 10000.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <math.h>
#include <ctype.h>
using namespace std;

// solution 1
class Solution {
public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    vector<int> result(nums.size());
    if (!nums.size()) return result;

    stack<int> s;
    int idx = 0, m = INT_MIN;

    for (int i = 0; i < 2 * nums.size(); i++) {
      idx = i % nums.size();
      m = max(m, nums[idx]);

      while (!s.empty() && nums[s.top()] < nums[idx]) {
        result[s.top()] = nums[idx];
        s.pop();
      }
      s.push(idx);
    }

    while (!s.empty()) {
      if (nums[s.top()] == m) {
        result[s.top()] = -1;
      }
      s.pop();
    }

    return result;
  }
};

// test
int main() {
  return 0;
}



