/*
 * https://leetcode.com/problems/contains-duplicate-ii/description/
 *
 * Given an array of integers and an integer k, find out whether there are two
 * distinct indices i and j in the array such that nums[i] = nums[j] and the
 * absolute difference between i and j is at most k.
 *
 */

#include <iostream>
#include <map>
#include <vector>
using namespace std;

// solution 1
class Solution {
public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    int len = nums.size();
    map<int, int> m;

    for (int i = 0; i < len; i++) {
      if (m.find(nums[i]) != m.end() && i - m[nums[i]] <= k) {
        return true;
      }
      m[nums[i]] = i;
    }

    return false;
  }
};


// test
int main() {
  Solution solution;

  vector<int> v1 = {7, 1, 5, 7, 6, 4};

  cout << solution.containsNearbyDuplicate(v1, 4) << endl;

  return 0;
}


