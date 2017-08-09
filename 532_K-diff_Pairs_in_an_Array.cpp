/*
 * https://leetcode.com/problems/k-diff-pairs-in-an-array/description/
 *
 * Given an array of integers and an integer k, you need to find the
 * number of unique k-diff pairs in the array. Here a k-diff pair is defined
 * as an integer pair (i, j), where i and j are both numbers in the array and
 * their absolute difference is k.
 *
 */

#include <iostream>
#include <set>
#include <vector>
using namespace std;


// solution 1
class Solution {
public:
  int findPairs(vector<int>& nums, int k) {
    if (k < 0) return 0;

    set<int> sumSet;
    set<int> numSet;

    for (int i : nums) {
      if (numSet.find(i + k) != numSet.end()) {
        sumSet.insert(2 * i + k);
      }

      if (numSet.find(i - k) != numSet.end()) {
        sumSet.insert(2 * i - k);
      }
      numSet.insert(i);
    }

    return sumSet.size();
  }
};


// test
int main() {
  Solution solution;

  vector<int> v1 = {3, 1, 4, 1, 5};
  vector<int> v2 = {1, 2, 3, 4, 5};
  vector<int> v3 = {1, 3, 1, 5, 4};

  cout << solution.findPairs(v1, 2) << endl;
  cout << solution.findPairs(v2, -1) << endl;
  cout << solution.findPairs(v3, 0) << endl;

  return 0;
}


