/*
 * https://leetcode.com/problems/roman-to-integer/#/description
 *
 * Given a sorted array and a target value, return the index if the target is found.
 * If not, return the index where it would be if it were inserted in order.
 *
 * You may assume no duplicates in the array.
 *
 */

#include <iostream>
#include <vector>
using namespace std;


// solution 1
class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] >= target) {
        return i;
      }
    }

    return nums.size();
  }
};


// test
int main() {
  Solution solution;

  vector<int> nums = {1,3,5,6};

  cout << solution.searchInsert(nums, 5) << endl;
  cout << solution.searchInsert(nums, 2) << endl;
  cout << solution.searchInsert(nums, 7) << endl;
  cout << solution.searchInsert(nums, 0) << endl;

  return 0;
}


