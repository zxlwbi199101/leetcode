/*
 * https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/
 *
 * Given an integer array, you need to find one continuous subarray that if you only sort this
 * subarray in ascending order, then the whole array will be sorted in ascending order, too.
 *
 * You need to find the shortest such subarray and output its length.
 *
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// solution 1
class Solution {
public:
  int findUnsortedSubarray(vector<int>& nums) {
    int len = nums.size();
    if (len <= 1) return 0;

    int front = 0;
    int back = len - 1;
    int minVal = INT_MAX;
    int maxVal = INT_MIN;

    while (front < len - 1 && nums[front] <= nums[front + 1]) front++;
    while (back > 0 && nums[back] >= nums[back - 1]) back--;

    if (front >= back) return 0;
    cout << front << "  " << back << endl;

    for (int i = front; i <= back; i++) {
      minVal = min(nums[i], minVal);
      maxVal = max(nums[i], maxVal);
    }

    for (int i = 0; i <= front; i++) {
      if (nums[i] > minVal) {
        front = i;
        break;
      }
    }

    for (int i = len - 1; i >= back; i--) {
      if (nums[i] < maxVal) {
        back = i;
        break;
      }
    }

    return back - front + 1;
  }
};


// test
int main() {
  Solution solution;

  vector<int> nums = {2,3,3,2,4};

  cout << solution.findUnsortedSubarray(nums) << endl;

  return 0;
}


