/*
 * https://leetcode.com/problems/next-permutation/description/
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 *
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 *
 * The replacement must be in-place, do not allocate extra memory.
 *
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
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
  void nextPermutation(vector<int>& nums) {
    if (nums.size() < 2) return;

    int lastASCIndex = 0;

    for (int i = nums.size() - 1; i > 0; i--) {
      if (nums[i - 1] < nums[i]) {
        lastASCIndex = i;
        break;
      }
    }

    if (lastASCIndex == 0) {
      sort(nums.begin(), nums.end());
      return;
    }

    // find last greater than nums[lastASCIndex - 1]
    int lastGTIndex = lastASCIndex;
    for (int i = nums.size() - 1; i >= lastASCIndex; i--) {
      if (nums[i] > nums[lastASCIndex - 1]) {
        swap(nums[i], nums[lastASCIndex - 1]);
        lastGTIndex = i;
        break;
      }
    }

    sort(nums.begin() + lastASCIndex + 1, nums.end());

  }
};
//1 3 2
//2 1 3
//5 4 6
// test
int main() {
  Solution solution;

  vector<int> nums = {3,1,2};
  solution.nextPermutation(nums);
  for (int i : nums) cout << i << endl;

  return 0;
}


