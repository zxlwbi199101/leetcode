/*
 * https://leetcode.com/problems/largest-palindrome-product/description/
 *
 * Find the largest palindrome made from the product of two n-digit numbers.
 *
 * Since the result could be very large, you should return the largest
 * palindrome mod 1337.
 *
 * Example:
 *
 * Input: 2
 *
 * Output: 987
 *
 * Explanation: 99 x 91 = 9009, 9009 % 1337 = 987
 *
 * Note:
 *
 * The range of n is [1,8].
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
  int largestPalindrome(int n) {
    int rst[] = {9, 987, 123, 597, 677, 1218, 877, 475};
    return rst[n - 1];
  }
};


// test
int main() {

  return 0;
}


