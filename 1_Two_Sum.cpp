/*
 * https://leetcode.com/problems/two-sum/tabs/description
 *
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 *
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

// solution 1
class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> index;
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
      if (index.find(target - nums[i]) == index.end()) {
        index[nums[i]] = i;
      } else {
        result.push_back(i);
        result.push_back(index[target - nums[i]]);
        break;
      }
    }

    return result;
  }
};


// test
int main() {
  Solution solution;

  vector<int> nums = {2, 12, 7, 11, 15};

  vector<int> res = solution.twoSum(nums, 9);

  for (int i : res) cout << i << endl;

  return 0;
}


