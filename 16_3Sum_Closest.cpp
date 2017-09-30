/*
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * Given an array S of n integers, find three integers in S such that the
 * sum is closest to a given number, target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 *
 * For example, given array S = {-1 2 1 -4}, and target = 1.
 *
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
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
  int threeSumClosest(vector<int>& nums, int target) {
    int length = nums.size();
    if (length < 3) return 0;
    int closest = nums[0] + nums[1] + nums[2];

    // prepare the array
    sort(nums.begin(), nums.end());

    for (int i = 0; i < length - 2; i++) {
      if (i && nums[i] == nums[i - 1]) continue;

      int j = i + 1, k = length - 1;
      while (j < k) {
        int sum = nums[i] + nums[j] + nums[k];

        if (abs(sum - target) < abs(closest - target)) {
          closest = sum;
        }

        if (sum > target) k--;
        else if (sum < target) j++;
        else return closest;
      }
    }

    return closest;
  }
};
// 1 2 3 4 5 6 7
// test
int main() {
  Solution solution;

  vector<int> nums = {0,1,2};

  cout << solution.threeSumClosest(nums, 0) << endl;

  return 0;
}


