/*
 * https://leetcode.com/problems/sort-colors/description/
 *
 * Given an array with n objects colored red, white or blue, sort them so
 * that objects of the same color are adjacent, with the colors in the order
 * red, white and blue.
 *
 * Here, we will use the integers 0, 1, and 2 to represent the color red, white,
 * and blue respectively.
 *
 * Note:
 * You are not suppose to use the library's sort function for this problem.
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
  // void sortColors(vector<int>& nums) {
  //   int counts[3] = {0,0,0};
  //   int index = 0;

  //   for (int n : nums) {
  //     counts[n]++;
  //     if (n == 0) nums[index++] = 0;
  //   }

  //   for (int i = 0; i < counts[1]; i++) nums[index++] = 1;
  //   for (int i = 0; i < counts[2]; i++) nums[index++] = 2;
  // }

  void sortColors(vector<int>& nums) {
    int reds = 0, whites = 0, blues = 0;

    for (int n : nums) {
      if (n == 0) {
        nums[blues++] = 2;
        nums[whites++] = 1;
        nums[reds++] = 0;
      } else if (n == 1) {
        nums[blues++] = 2;
        nums[whites++] = 1;
      } else {
        nums[blues++] = 2;
      }
    }
  }
};


// test
int main() {
  Solution solution;

  vector<int> nums = {0,0,0,1,0,0,1,2,1,1,2};
  solution.sortColors(nums);

  for (int n : nums) cout << n << endl;

  return 0;
}

