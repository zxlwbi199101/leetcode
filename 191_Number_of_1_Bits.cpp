/*
 * https://leetcode.com/problems/number-of-1-bits/description/
 *
 * Write a function that takes an unsigned integer and returns the number of
 * '1' bits it has (also known as the Hamming weight).
 *
 * For example, the 32-bit integer ’11' has binary representation
 * 00000000000000000000000000001011, so the function should return 3.
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
  int hammingWeight(uint32_t n) {
    int result = 0;

    while (n != 0) {
      result += (n & 1);
      n >>= 1;
    }

    return result;
  }
};


// test
int main() {

  return 0;
}


