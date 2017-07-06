/*
 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/#/description
 *
 * Given an array of integers that is already sorted in ascending order,
 * find two numbers such that they add up to a specific target number.
 *
 * The function twoSum should return indices of the two numbers such that
 * they add up to the target, where index1 must be less than index2. Please note
 * that your returned answers (both index1 and index2) are not zero-based.
 *
 * You may assume that each input would have exactly one solution and you may
 * not use the same element twice.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// solution 1
class Solution {
public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    map<int, int> indexMap;

    for (int i = 0; i < numbers.size(); i++) indexMap[numbers[i]] = i;

    for (int i = 0; i < numbers.size(); i++) {
      if (indexMap.find(target - numbers[i]) != indexMap.end()) {
        int temp = indexMap[target - numbers[i]];
        return vector<int> {min(i, temp) + 1, max(i, temp) + 1};
      }
    }

    return vector<int> ();
  }
};


// test
int main() {
  Solution solution;
  vector<int> v = {2, 7, 11, 15};

  vector<int> result = solution.twoSum(v, 9);

  for (int s : result) cout << s << endl;

  return 0;
}


