/*
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * A zero-indexed array A consisting of N different integers is given.
 * The array contains all integers in the range [0, N - 1].
 *
 * Sets S[K] for 0 <= K < N are defined as follows:
 *
 * S[K] = { A[K], A[A[K]], A[A[A[K]]], ... }.
 *
 * Sets S[K] are finite for each K and should NOT contain duplicates.
 *
 * Write a function that given an array A consisting of N integers, return the
 * size of the largest set S[K] for this array.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

// solution 1
class Solution {
public:
  int arrayNesting(vector<int>& nums) {
    int imax = INT_MIN;

    for (int i = 0, next = -1; i < nums.size(); i++) {
      next = nums[i];
      if (next < 0) continue;

      int steps = 1;
      while (i != next) {
        nums[next] *= -1;
        next = abs(nums[next]);
        steps++;
      }
      imax = max(imax, steps);
    }

    return imax;
  }
};

// test
int main() {
  Solution solution;

  vector<int> nums = {0};
  // vector<int> nums = {4,5,6,7,0,1,2};
  // vector<int> nums = {0,1,2,4,5,6,7};
  cout << solution.arrayNesting(nums) << endl;

  return 0;
}


