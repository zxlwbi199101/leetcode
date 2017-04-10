/*
 * https://leetcode.com/problems/max-consecutive-ones/#/description
 *
 * Given a binary array, find the maximum number of consecutive 1s in this array.
 *
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;


// solution 1
class Solution {
public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int max = 0;
    int currentMax = 0;

    for (int n : nums) {
      if (n == 1) {
        currentMax++;
        max = currentMax > max ? currentMax : max;
      } else {
        currentMax = 0;
      }
    }

    return max;
  }
};


// test
int main() {
  Solution solution;

  vector<int> nums = {1, 1, 0, 1, 1, 1};
  cout << solution.findMaxConsecutiveOnes(nums) << endl;

  return 0;
}


