/*
 * https://leetcode.com/problems/reverse-bits/description/
 *
 * Reverse bits of a given 32 bits unsigned integer.
 *
 * For example, given input 43261596 (represented in binary as
 * 00000010100101000001111010011100), return 964176192 (represented in binary
 * as 00111001011110000010100101000000).
 *
 * Follow up:
 * If this function is called many times, how would you optimize it?
 *
 * Related problem: Reverse Integer
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

// solution 1
class Solution {
public:
  // uint32_t reverseBits(uint32_t n) {
  //   uint32_t mask = 2147483648; // 2^31
  //   uint32_t result = 0;

  //   for (int i = 0; n != 0; i++) {
  //     if (n % 2 == 1) {
  //       result |= (mask >> i);
  //     }
  //     n >>= 1;
  //   }

  //   return result;
  // }

  uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;

    for (int i = 0; i < 32; i++) {
      result <<= 1;
      if (n % 2 == 1) {
        result |= 1;
      }
      n >>= 1;
    }

    return result;
  }
};

// test
int main() {
  Solution solution;
  cout << solution.reverseBits(2147483648) << endl;
  return 0;
}


