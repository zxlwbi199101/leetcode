/*
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * Given a collection of integers that might contain duplicates, nums,
 * return all possible subsets.
 *
 * Note: The solution set must not contain duplicate subsets.
 *
 * For example,
 * If nums = [1,2,2], a solution is:
 *
 * [
 *   [2],
 *   [1],
 *   [1,2,2],
 *   [2,2],
 *   [1,2],
 *   []
 * ]
 *
 *
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

// solution 1
class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> results = {{}};
    vector<int> temp;

    int consecutive_end = 0;
    for (int i = 0; i < nums.size(); i++) {
      int len = results.size();
      int consecutive_start = 0;

      if (i && nums[i] == nums[i - 1]) {
        consecutive_start = consecutive_end;
      }
      for (int j = consecutive_start; j < len; j++) {
        temp = results[j];
        results.push_back(temp);
        results.back().push_back(nums[i]);
      }
      consecutive_end = len;
    }

    return results;
  }
};

// test
int main() {
  Solution solution;

  vector<int> nums = {1,2,2};

  for (vector<int> i : solution.subsetsWithDup(nums)) {
    for (int j : i) cout << j << " ";
    cout << endl;
  }

  return 0;
}


