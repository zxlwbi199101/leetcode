/*
 * https://leetcode.com/problems/number-complement/#/description
 *
 * Given a positive integer, output its complement number.
 * The complement strategy is to flip the bits of its binary representation.
 *
 */

#include <iostream>
using namespace std;


// solution 1
class Solution {
public:
  int findComplement(int num) {
    if (num == 0) {
      return num;
    }

    int heads = 0;
    for (; num << heads >> heads == num && heads < 32; heads++) {}

    return ~(num << heads) >> heads;
  }
};


// test case
int main() {
  Solution solution;
  cout << solution.findComplement(5) << endl;
  cout << solution.findComplement(2) << endl;

  return 0;
}
