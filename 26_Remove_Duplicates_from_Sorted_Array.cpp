/*
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/tabs/description
 *
 * Given a sorted array, remove the duplicates in place such that each element appear
 * only once and return the new length.
 *
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 *
 * For example,
 * Given input array nums = [1,1,2],
 *
 * Your function should return length = 2, with the first two elements of nums being 1 and 2
 * respectively. It doesn't matter what you leave beyond the new length.
 *
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;


// solution 1
class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int len = 0;
    int last = INT_MAX;

    for (int n : nums) {
      if (last != n) {
        len++;
        last = n;
        nums[len - 1] = n;
      }
    }

    return len;
  }
};


// test
int main() {
  Solution solution;

  vector<int> nums = {1,2};

  cout << solution.removeDuplicates(nums);

  return 0;
}


