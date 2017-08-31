/*
 * https://leetcode.com/problems/summary-ranges/description/
 *
 * Given a sorted integer array without duplicates, return the summary of
 * its ranges.
 *
 * Example 1:
 * Input: [0,1,2,4,5,7]
 * Output: ["0->2","4->5","7"]
 *
 * Example 2:
 * Input: [0,2,3,4,6,8,9]
 * Output: ["0","2->4","6","8->9"]
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
  vector<string> summaryRanges(vector<int>& nums) {
    vector<string> result;
    if (!nums.size()) return result;

    int start = nums[0];
    int last = start;
    nums.push_back(0);

    for (int i = 1; i < nums.size(); i++) {
      if (last + 1 == nums[i] && i < nums.size() - 1) {
        last++;
      } else {
        if (start == last) {
          result.push_back(to_string(start));
        } else {
          result.push_back(to_string(start) + "->" + to_string(last));
        }

        last = start = nums[i];
      }
    }

    return result;
  }
};

// test
int main() {
  Solution solution;

  vector<int> nums = {0,2,3,4,6,8,9};
  vector<string> result = solution.summaryRanges(nums);

  for (string n : result) cout << n << endl;

  return 0;
}


