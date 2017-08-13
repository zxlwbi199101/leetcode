/*
 * https://leetcode.com/problems/rotate-array/description/
 *
 * Rotate an array of n elements to the right by k steps.
 * For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

// solution 1
class Solution {
public:
  void rotate(vector<int>& nums, int k) {
    int len = nums.size();
    k = k % len;

    int counter = 0;
    int temp1 = 0;
    int temp2 = 0;
    int nextIdx = 0;
    for (int i = 0; i < k && counter < len; i++) {
      nextIdx = i;
      temp1 = nums[i];

      while (counter < len) {
        nextIdx = (nextIdx + k) % len;
        counter++;

        temp2 = nums[nextIdx];
        nums[nextIdx] = temp1;
        temp1 = temp2;

        if (nextIdx == i) {
          break;
        }
      }
    }
  }
};

// test
int main() {
  Solution solution;

  vector<int> nums = {1};

  solution.rotate(nums, 3);

  for (int i : nums) {
    cout << i << " " << endl;
  }

  return 0;
}


