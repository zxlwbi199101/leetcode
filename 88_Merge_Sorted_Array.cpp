/*
 * https://leetcode.com/problems/merge-sorted-array/description/
 *
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 *
 */

#include <iostream>
#include <vector>
using namespace std;

// solution 1
class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    for (int i = m-- + n-- - 1; i >= 0; i--) {
      if (nums1[m] > nums2[n]) nums1[i] = nums1[m--];
      else nums1[i] = nums2[n--];
    }
  }
};


// test
int main() {
  Solution solution;

  vector<int> nums1 = {1,3,5,6,0,0,0,0};
  vector<int> nums2 = {2,3,5,7};

  solution.merge(nums1, 4, nums2, 4);

  for (int i : nums1) {
    cout << i << endl;
  }

  return 0;
}


