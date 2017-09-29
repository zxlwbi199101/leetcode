/*
 * https://leetcode.com/problems/4sum/description/
 *
 * Given an array S of n integers, are there elements a, b, c, and d in S
 * such that a + b + c + d = target? Find all unique quadruplets in the array
 * which gives the sum of target.
 *
 * Note: The solution set must not contain duplicate quadruplets.
 *
 * For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
 *
 * A solution set is:
 * [
 *   [-1,  0, 0, 1],
 *   [-2, -1, 1, 2],
 *   [-2,  0, 0, 2]
 * ]
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
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int length = nums.size();
    vector<vector<int>> result;
    if (length < 4) return result;

    // prepare the array
    sort(nums.begin(), nums.end());
    unordered_map<int, int> m;
    for (int i = 0; i < length; i++) m[nums[i]] = i;

    for (int i = 0; i < length - 3; i++) {
      if (i && nums[i] == nums[i - 1]) continue;
      if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
      if (nums[i] + nums[length - 1] + nums[length - 2] + nums[length - 3] < target) continue;

      for (int j = i + 1; j < length - 2; j++) {
        if (j > i + 1 && nums[j] == nums[j - 1]) continue;
        if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
        if (nums[i] + nums[j] + nums[length - 1] + nums[length - 2] < target) continue;

        for (int k = j + 1; k < length - 1; k++) {
          if (k > j + 1 && nums[k] == nums[k - 1]) continue;
          int sum = nums[i] + nums[j] + nums[k];
          if (sum + nums[k + 1] > target) break;
          if (sum + nums[length - 1] < target) continue;

          if (m[target - sum] > k) {
            result.push_back(vector<int>{nums[i], nums[j], nums[k], target - sum});
          }
        }
      }
    }

    return result;
  }
};
// 1 2 3 4 5 6 7
// test
int main() {
  Solution solution;

  vector<int> nums = {-3,-2,-1,0,0,1,2,3};

  vector<vector<int>> result = solution.fourSum(nums, 0);

  for (vector<int> row : result) {
    for (int i : row) cout << i << " ";
    cout << endl;
  }

  return 0;
}


