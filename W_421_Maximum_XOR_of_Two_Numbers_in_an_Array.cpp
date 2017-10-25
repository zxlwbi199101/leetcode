/*
 * https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/
 *
 * Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.
 *
 * Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.
 *
 * Could you do this in O(n) runtime?
 *
 * Example:
 *
 * Input: [3, 10, 5, 25, 2, 8]
 *
 * Output: 28
 *
 * Explanation: The maximum result is 5 ^ 25 = 28.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <math.h>
#include <ctype.h>
using namespace std;

// solution 1
class Solution {
public:
  int findMaximumXOR(vector<int>& nums) {
    int mask = 0, result = 0;

    for (int i = 31; i >= 0; i--) {
      mask |= 1 << i;
      int temp = result | (1 << i);

      unordered_set<int> s;
      for (int n : nums) s.insert(n & mask);

      for (int p : s) {
        if (s.find(temp ^ p) != s.end()) {
          result = temp;
          break;
        }
      }
    }

    return result;
  }
};

// test
int main() {
  return 0;
}



