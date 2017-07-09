/*
 * https://leetcode.com/problems/contains-duplicate/#/description
 *
 * Given an array of integers, find if the array contains any duplicates.
 * Your function should return true if any value appears at least twice in the array,
 * and it should return false if every element is distinct.
 *
 */

#include <iostream>
#include <set>
#include <vector>
using namespace std;


// solution 1
class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    if (nums.size() < 2) return false;

    set<int> s;

    for (int i : nums) {
      if (s.find(i) != s.end()) return true;

      s.insert(i);
    }

    return false;
  }
};


// test
int main() {
  Solution solution;

  vector<int> v = {1,2,3,4,5};

  cout << solution.containsDuplicate(v) << endl;

  return 0;
}


