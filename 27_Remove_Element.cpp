/*
 * https://leetcode.com/problems/remove-element/tabs/description
 *
 * Given an array and a value, remove all instances of that value in place and return the new length.
 *
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 *
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 *
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;


// solution 1
class Solution {
public:
  int removeElement(vector<int>& nums, int val) {
    int len = 0;

    for (int n : nums) {
      if (n != val) nums[len++] = n;
    }

    return len;
  }
};


// test
int main() {
  Solution solution;

  vector<int> nums = {3,2,2,3};

  cout << solution.removeElement(nums, 3) << endl;

  return 0;
}


