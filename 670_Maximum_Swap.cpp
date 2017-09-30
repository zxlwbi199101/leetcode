/*
 * https://leetcode.com/problems/maximum-swap/description/
 *
 * Given a non-negative integer, you could swap two digits at most once
 * to get the maximum valued number. Return the maximum valued number you
 * could get.
 *
 * Example 1:
 * Input: 2736
 * Output: 7236
 * Explanation: Swap the number 2 and the number 7.
 * Example 2:
 * Input: 9973
 * Output: 9973
 * Explanation: No swap.
 * Note:
 * The given number is in the range [0, 108]
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <math.h>
using namespace std;

// solution 1
class Solution {
public:
  int maximumSwap(int num) {
    vector<int> nums;
    priority_queue<int> q;

    for (char c : to_string(num)) {
      nums.push_back(c - '0');
      q.push(c - '0');
    }

    int front = 0;
    for (; front < nums.size(); front++) {
      if (nums[front] != q.top()) {
        break;
      }
      q.pop();
    }

    if (q.empty()) return num;

    int ret = 0, found = false;
    for (int i = nums.size() - 1; i >= 0; i--) {
      if (!found && nums[i] == q.top()) {
        found = true;
        swap(nums[i], nums[front]);
      }
      ret += pow(10, nums.size() - 1 - i) * nums[i];
    }

    return ret;
  }
};
// 1 2 3 4 5 6 7
// test
int main() {
  Solution solution;
  cout << solution.maximumSwap(0) << endl;

  return 0;
}


