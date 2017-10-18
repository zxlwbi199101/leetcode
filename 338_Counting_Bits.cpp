/*
 * https://leetcode.com/problems/counting-bits/description/
 *
 * Given a non negative integer number num. For every numbers i in the range
 * 0 ≤ i ≤ num calculate the number of 1's in their binary representation and
 * return them as an array.
 *
 * Example:
 * For num = 5 you should return [0,1,1,2,1,2].
 *
 * Follow up:
 *
 * It is very easy to come up with a solution with run time O(n*sizeof(integer)).
 * But can you do it in linear time O(n) /possibly in a single pass?
 * Space complexity should be O(n).
 * Can you do it like a boss? Do it without using any builtin function like
 * __builtin_popcount in c++ or in any other language.
 *
 */

#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

// solution 1
class Solution {
public:
  // vector<int> countBits(int num) {
  //   vector<int> result = {0};
  //   if (num == 0) return result;

  //   int cur = 1;
  //   while (cur <= num / 2) { // avoid overflow
  //     cur *= 2;
  //     int len = result.size();

  //     for (int j = 0; i < len; i++) {
  //       result.push_back(result[j] + 1);
  //     }
  //   }

  //   for (int i = 0; i <= num - cur; i++) {
  //     result.push_back(result[i] + 1);
  //   }

  //   return result;
  // }

  vector<int> countBits(int num) {
    vector<int> result = {0};

    int i = 1;
    while (i <= num) {
      int len = result.size();
      for (int j = 0; j < len && i <= num; j++, i++) {
        result.push_back(result[j] + 1);
      }
    }

    return result;
  }
};


// test
int main() {
  return 0;
}


