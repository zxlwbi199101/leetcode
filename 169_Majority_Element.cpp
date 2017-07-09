/*
 * https://leetcode.com/problems/majority-element/#/description
 *
 * Given an array of size n, find the majority element. The majority element is the element
 * that appears more than ⌊ n/2 ⌋ times.
 * You may assume that the array is non-empty and the majority element always exist in the array.
 *
 */

#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

// solution 1
class Solution {
public:
  int majorityElement(vector<int>& nums) {
    map<int, int> m;
    int max = nums.size() / 2;

    for (int i : nums) {
      if (m.find(i) != m.end()) m[i]++;
      else m[i] = 1;
    }

    for (pair<int, int> p : m) {
      if (p.second > max) return p.first;
    }

    return 0;
  }
};


// test
int main() {
  Solution solution;
  vector<int> v = {1};

  cout << solution.majorityElement(v) << endl;

  return 0;
}


