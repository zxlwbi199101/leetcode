/*
 * https://leetcode.com/problems/third-maximum-number/description/
 *
 * Given a non-empty array of integers, return the third maximum number
 * in this array. If it does not exist, return the maximum number.
 * The time complexity must be in O(n).
 *
 */

#include <iostream>
#include <vector>
#include <set>
using namespace std;

// solution 1
class Solution {
public:
  int thirdMax(vector<int>& nums) {
    set<int> s;

    for (int i : nums) {
      s.insert(i);
    }

    if (s.size() >= 3) {
      set<int>::iterator it = s.end();
      advance(it, -3);
      return *it;
    }
    return *(--s.end());
  }
};


// test
int main() {
  Solution solution;

  vector<int> nums1 = {1,3,5,6,0,0,0,0};
  vector<int> nums2 = {1};

  cout << solution.thirdMax(nums1) << endl;
  cout << solution.thirdMax(nums2) << endl;
  return 0;
}


