/*
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * Find the contiguous subarray within an array (containing at least one number) which has the largest product.
 *
 * For example, given the array [2,3,-2,4],
 * the contiguous subarray [2,3] has the largest product = 6.
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
  int maxProduct(vector<int>& nums) {
    int result = nums[0];
    int imax = result;
    int imin = result;

    for (int i = 1, n = 0; i < nums.size(); i++) {
      n = nums[i];

      if (n < 0) {
        swap(imax, imin);
      }

      imax = max(imax * n, n);
      imin = min(imin * n, n);

      result = max(imax, result);
    }

    return result;
  }
};

// test
int main() {
  Solution solution;

  vector<int> nums = {-4,-3,-2};
  // vector<int> nums = {4,5,6,7,0,1,2};
  // vector<int> nums = {0,1,2,4,5,6,7};
  cout << solution.maxProduct(nums) << endl;

  return 0;
}


