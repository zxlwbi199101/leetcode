/*
 * https://leetcode.com/problems/3sum/description/
 *
 * Given an array S of n integers, are there elements a, b, c in S such
 * that a + b + c = 0? Find all unique triplets in the array which gives
 * the sum of zero.
 *
 * Note: The solution set must not contain duplicate triplets.
 *
 * For example, given array S = [-1, 0, 1, 2, -1, -4],
 *
 * A solution set is:
 * [
 *   [-1, 0, 1],
 *   [-1, -1, 2]
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
  vector<vector<int>> threeSum(vector<int>& nums) {
    int length = nums.size();
    const int target = 0;
    vector<vector<int>> result;
    if (length < 3) return result;

    // prepare the array
    sort(nums.begin(), nums.end());

    for (int i = 0; i < length - 2; i++) {
      if (i && nums[i] == nums[i - 1]) continue;
      if (nums[i] + nums[i + 1] + nums[i + 2] > target) break;
      if (nums[i] + nums[length - 1] + nums[length - 2] < target) continue;

      int j = i + 1, k = length - 1;
      while (j < k) {
        if (j > i + 1 && nums[j] == nums[j - 1]) {
          j++;
          continue;
        }
        if (k < length - 1 && nums[k] == nums[k + 1]) {
          k--;
          continue;
        }
        int sum = nums[i] + nums[j] + nums[k];

        if (sum < target) j++;
        else if (sum > target) k--;
        else result.push_back(vector<int> {nums[i], nums[j++], nums[k--]});
      }
    }

    return result;
  }
};
// 1 2 3 4 5 6 7
// test
int main() {
  Solution solution;

  vector<int> nums = {-1, 0, 1, 2, -1, -4};

  auto results = solution.threeSum(nums);
  for (auto row : results) {
    for (int r : row) cout << r << " ";
    cout << endl;
  }

  return 0;
}


