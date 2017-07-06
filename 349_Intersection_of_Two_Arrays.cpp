/*
 * https://leetcode.com/problems/intersection-of-two-arrays/#/description
 *
 * Given two arrays, write a function to compute their intersection.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

// solution 1
class Solution {
public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    set<int> numSet;
    vector<int> result;

    for (int i : nums1) numSet.insert(i);
    for (int i : nums2) {
      auto index = numSet.find(i);
      if (index != numSet.end()) {
        result.push_back(i);
        numSet.erase(index);
      }
    }

    return result;
  }
};


// test
int main() {
  Solution solution;
  vector<int> v1 = {1, 2, 2, 1};
  vector<int> v2 = {2, 2};

  vector<int> result = solution.intersection(v1, v2);

  for (int s : result) cout << s << endl;

  return 0;
}


