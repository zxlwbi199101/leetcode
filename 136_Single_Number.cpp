/*
 * https://leetcode.com/problems/single-number/#/description
 *
 * Given an array of integers, every element appears twice except for one.
 * Find that single one.
 *
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;


// solution 1
class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int result = 0;

    for (int n : nums) {
      result ^= n;
    }

    return result;
  }
};


// test
int main() {
  Solution solution;

  vector<int> nums = {1, 2, 0, 1, 2, 0, 3};
  cout << solution.singleNumber(nums) << endl;

  return 0;
}


