/*
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * Given a collection of candidate numbers (C) and a target number (T),
 * find all unique combinations in C where the candidate numbers sums to T.
 *
 * Each number in C may only be used once in the combination.
 *
 * Note:
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
 * A solution set is:
 * [
 *   [1, 7],
 *   [1, 2, 5],
 *   [2, 6],
 *   [1, 1, 6]
 * ]
 *
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;


// solution 1
class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<vector<int>> cache = { { 0 } };

    sort(candidates.begin(), candidates.end());

    int last = 0;
    for (int i = 0; i < candidates.size(); i++) {
      int len = cache.size();
      int start = 0;

      if (i && candidates[i - 1] == candidates[i]) {
        start = last;
      }

      for (int j = start; j < len; j++) {
        int sum = cache[j].back() + candidates[i];

        if (sum < target) {
          cache.push_back(cache[j]);
          cache.back()[cache.back().size() - 1] = candidates[i];
          cache.back().push_back(sum);
        } else if (sum == target) {
          result.push_back(cache[j]);
          result.back()[cache[j].size() - 1] = candidates[i];
        }
      }

      last = len;
    }

    return result;
  }
};

// test
int main() {
  Solution solution;

  vector<int> nums = {1,2,2,3,4};

  for (auto row : solution.combinationSum2(nums, 8)) {
    for (auto r : row) cout << r << " ";
    cout << endl;
  }

  return 0;
}


