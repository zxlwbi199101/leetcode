/*
 * https://leetcode.com/problems/missing-number/#/description
 *
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
 * find the one that is missing from the array.
 *
 * For example,
 * Given nums = [0, 1, 3] return 2.
 *
 */

#include <iostream>
#include <vector>
#include <map>
#include <math.h>
using namespace std;

// solution 1
class Solution {
public:
  int missingNumber(vector<int>& nums) {
    int sum = 0;

    for (int i : nums) sum += i;

    return (nums.size()) * (nums.size() + 1) / 2 - sum;
  }
};


// test
int main() {
  Solution solution;

  vector<int> n1 = {0,1,2,3,4,5,6,8};

  cout << solution.missingNumber(n1) << endl;

  return 0;
}


