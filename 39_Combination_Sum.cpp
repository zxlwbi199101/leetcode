/*
 * https://leetcode.com/problems/combination-sum/description/
 *
 * Given a set of candidate numbers (C) (without duplicates) and a target
 * number (T), find all unique combinations in C where the candidate numbers
 * sums to T.
 *
 * The same repeated number may be chosen from C unlimited number of times.
 *
 * Note:
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set [2, 3, 6, 7] and target 7,
 * A solution set is:
 * [
 *   [7],
 *   [2, 2, 3]
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
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());

    vector<vector<int>> result;
    vector<vector<int>> cache = { {} };
    vector<int> sums = { 0 };

    for (int c : candidates) {
      int len = cache.size();

      for (int i = 0; i < len; i++) {
        for (int j = 1, sum = sums[i] + c; sum <= target; j++, sum += c) {
          if (sum == target) {
            vector<int> list = cache[i];
            list.resize(list.size() + j, c);
            result.push_back(list);
          } else if (sum + c < target) {
            vector<int> list = cache[i];
            list.resize(list.size() + j, c);
            cache.push_back(list);
            sums.push_back(sum);
          }
        }
      }
    }

    return result;
  }
};

// test
int main() {
  Solution solution;

  vector<int> nums = {2,3,6,7};

  for (auto row : solution.combinationSum(nums, 7)) {
    for (auto r : row) cout << r << " ";
    cout << endl;
  }

  return 0;
}


