/*
 * https://leetcode.com/problems/majority-element-ii/description/
 *
 * Given an integer array of size n, find all elements that appear more than
 * ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.
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
  vector<int> majorityElement(vector<int>& nums) {
    int counter1 = 0;
    int counter2 = 0;
    int num1 = 0;
    int num2 = 0;

    for (int n : nums) {
      if (counter1 == 0 && (!counter2 || num2 != n)) {
        num1 = n;
        counter1++;
      } else if (num1 == n) {
        counter1++;
      } else if (counter2 == 0) {
        num2 = n;
        counter2++;
      } else if (num2 == n) {
        counter2++;
      } else if (num1 != n && num2 != n) {
        counter1--;
        counter2--;
      }
    }

    vector<int> result;
    if (counter1 > 0) counter1 = 1;
    if (counter2 > 0) counter2 = 1;

    for (int n : nums) {
      if (counter1 > 0 && n == num1) counter1++;
      if (counter2 > 0 && n == num2) counter2++;
    }

    if (counter1 && (counter1 - 1) > (nums.size() / 3)) result.push_back(num1);
    if (counter2 && (counter2 - 1) > (nums.size() / 3)) result.push_back(num2);

    return result;
  }
};

// test
int main() {
  Solution solution;

  vector<int> nums = {3,2,3};
  vector<int> result = solution.majorityElement(nums);

  for (int n : result) cout << n << endl;

  return 0;
}


