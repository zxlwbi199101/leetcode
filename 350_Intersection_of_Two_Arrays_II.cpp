/*
 * https://leetcode.com/problems/intersection-of-two-arrays-ii/#/description
 *
 * Given two arrays, write a function to compute their intersection.
 *
 * Example:
 * Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].
 *
 * Note:
 * Each element in the result should appear as many times as it shows in both arrays.
 * The result can be in any order.
 * Follow up:
 * What if the given array is already sorted? How would you optimize your algorithm?
 * What if nums1's size is small compared to nums2's size? Which algorithm is better?
 * What if elements of nums2 are stored on disk, and the memory is limited such that you
 * cannot load all elements into the memory at once?
 *
 *
 */

#include <iostream>
#include <vector>
#include <map>
#include <math.h>
using namespace std;

// solution 1
class Solution {
public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result;
    if (!nums1.size() || !nums2.size()) return result;

    map<int, int> numMap;
    for (int i : nums1) numMap[i]++;
    for (int i : nums2) {
      if (numMap.find(i) != numMap.end()) {
        if (numMap[i] > 0) result.push_back(i);
        numMap[i]--;
      }
    }

    return result;
  }
};


// test
int main() {
  Solution solution;

  vector<int> n1 = {1};
  vector<int> n2 = {1,1};

  vector<int> result = solution.intersect(n1, n2);
  for (int r : result) cout << r << endl;

  return 0;
}


