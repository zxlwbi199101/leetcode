/*
 * https://leetcode.com/problems/game-of-life/description/
 *
 * Given an array nums containing n + 1 integers where each integer is between 
 * 1 and n (inclusive), prove that at least one duplicate number must exist. 
 * Assume that there is only one duplicate number, find the duplicate one.
 * 
 * Note:
 * You must not modify the array (assume the array is read only).
 * You must use only constant, O(1) extra space.
 * Your runtime complexity should be less than O(n2).
 * There is only one duplicate number in the array, but it could be repeated 
 * more than once.
 * 
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <math.h>
using namespace std;

// solution 1

// a: from start to intersection 
// b: length of the circle a + b + x = 2 (a + x)
// x: from intersection to first meet point
//
// a + b + x = 2 * (a + x)
// b = a + x; a = b - x;

class Solution {
public:
  int findDuplicate(vector<int>& nums) {
    int hare = nums[nums[0]], tortoise = nums[0];
    while (hare != tortoise) {
      hare = nums[nums[hare]];
      tortoise = nums[tortoise];
    }

    hare = 0;
    while (hare != tortoise) {
      hare = nums[hare];
      tortoise = nums[tortoise];
    }

    return hare;
  }
};

// test
int main() {
  Solution solution;

  vector<int> nums = {1,3,4,2,2};
  cout << solution.findDuplicate(nums) << endl;

  return 0;
}

