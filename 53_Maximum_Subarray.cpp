/*
 * https://leetcode.com/problems/maximum-subarray/discuss/
 *
 * Find the contiguous subarray within an array (containing at least one number) which
 * has the largest sum.
 *
 * For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
 * the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 *
 */

#include <iostream>
#include <map>
#include <vector>
using namespace std;

// solution 1
class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int sum = nums[0];
    int maxSum = nums[0];

    for (int i = 1; i < nums.size(); i++) {
      sum = max(nums[i], sum + nums[i]);
      maxSum = max(maxSum, sum);
    }

    return maxSum;
  }
};


// test
int main() {
  Solution solution;

  vector<int> v1 = {-2,1,-3,4,-1,2,1,-5,4};

  cout << solution.maxSubArray(v1) << endl;

  return 0;
}


