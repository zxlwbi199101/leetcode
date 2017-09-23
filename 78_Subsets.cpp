/*
 * https://leetcode.com/problems/subsets/description/
 *
 * Given a set of distinct integers, nums, return all possible subsets.
 *
 * Note: The solution set must not contain duplicate subsets.
 *
 * For example,
 * If nums = [1,2,3], a solution is:
 *
 * [
 *   [3],
 *   [1],
 *   [2],
 *   [1,2,3],
 *   [1,3],
 *   [2,3],
 *   [1,2],
 *   []
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
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    result.push_back(vector<int>());

    for (int n : nums) {
      int len = result.size();

      for (int i = 0; i < len; i++) {
        result.push_back(result[i]);
        result.back().push_back(n);
      }
    }

    return result;
  }
};


// test
int main() {
  Solution solution;

  vector<int> w1 = {1,2,3};
  vector<vector<int>> result = solution.subsets(w1);

  for (vector<int> r : result) {
    for (int i : r) cout << i << " ";
    cout << endl;
  }

  return 0;
}

