/*
 * https://leetcode.com/problems/sqrtx/description/
 *
 * The set S originally contains numbers from 1 to n. But unfortunately, due
 * to the data error, one of the numbers in the set got duplicated to another
 * number in the set, which results in repetition of one number and loss of
 * another number.
 *
 * Given an array nums representing the data status of this set after the error.
 * Your task is to firstly find the number occurs twice and then find the number
 * that is missing. Return them in the form of an array.
 *
 * Example 1:
 * Input: nums = [1,2,2,4]
 * Output: [2,3]
 * Note:
 * The given array size will in the range [2, 10000].
 * The given array's numbers won't have any order.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <math.h>
#include <ctype.h>
using namespace std;

// solution 1
class Solution {
public:
  vector<int> findErrorNums(vector<int>& nums) {
    int sum = 0;
    int duplicated = 0;

    for (int i = 0; i < nums.size(); i++) {
      sum += abs(nums[i]);
      int index = abs(nums[i]) - 1;

      if (nums[index] < 0) duplicated = index + 1;
      else nums[index] *= -1;
    }

    vector<int> result (2, duplicated);
    result[1] = (1 + nums.size()) * nums.size() / 2 - sum + duplicated;

    return result;
  }
};

// test
int main() {
  Solution solution;
  vector<int> nums = {1,2,4,4};
  for (auto n : solution.findErrorNums(nums))
    cout << n << endl;

  return 0;
}



