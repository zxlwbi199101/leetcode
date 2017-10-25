/*
 * https://leetcode.com/problems/next-greater-element-ii/description/
 *
 * Shuffle a set of numbers without duplicates.
 *
 * Example:
 *
 * // Init an array with set 1, 2, and 3.
 * int[] nums = {1,2,3};
 * Solution solution = new Solution(nums);
 *
 * // Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3]
 * must equally likely to be returned.
 * solution.shuffle();
 *
 * // Resets the array back to its original configuration [1,2,3].
 * solution.reset();
 *
 * // Returns the random shuffling of array [1,2,3].
 * solution.shuffle();
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <math.h>
#include <ctype.h>
using namespace std;

// solution 1
class Solution {
public:
  vector<int> original;
  vector<int> arr;

  Solution(vector<int> nums) {
    original = nums;
    arr = vector<int>(nums);
  }

  /** Resets the array to its original configuration and return it. */
  vector<int> reset() {
    return original;
  }

  /** Returns a random shuffling of the array. */
  vector<int> shuffle() {
    for (int i = 0; i < arr.size(); i++) {
      swap(arr[rand() % arr.size()], arr[i]);
    }
    return arr;
  }
};

// test
int main() {
  return 0;
}



