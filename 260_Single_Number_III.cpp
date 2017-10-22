/*
 * https://leetcode.com/problems/single-number-iii/description/
 *
 * Find the two elements that appear only once.
 *
 * For example:
 *
 * Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
 *
 * Note:
 * The order of the result is not important. So in the above example, [5, 3] is also correct.
 * Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
 *
 */

#include <iostream>
#include <string>
#include <stack>
using namespace std;

// solution 1
class Solution {
public:
  vector<int> singleNumber(vector<int>& nums) {
    vector<int> result = {0, 0};
    int diff = 0;
    for (int n : nums) nums ^= n;

    // devide nums into 2 group by right most bit 1
    diff &= -diff;
    for (int n : nums) {
      if (n & diff) {
        result[0] ^= n;
      } else {
        result[1] ^= n;
      }
    }

    return result;
  }
};


// test
int main() {
  return 0;
}


