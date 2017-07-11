/*
 * https://leetcode.com/problems/reverse-string-ii/#/description
 *
 * Given a string and an integer k, you need to reverse the first k characters
 * for every 2k characters counting from the start of the string. If there are
 * less than k characters left, reverse all of them. If there are less than 2k
 * but greater than or equal to k characters, then reverse the first k characters
 * and left the other as original.
 *
 */

#include <iostream>
#include <vector>
#include <map>
#include <math.h>
using namespace std;

// solution 1
class Solution {
public:
  string reverseStr(string s, int k) {
    for (int i = 0; i < s.size(); i += k * 2) {
      int left = (i + k) > s.size() ? (s.size() - i) : k;

      for (int j = 0; j < left / 2; j++) {
        swap(s[i + j], s[i + left - j - 1]);
      }
    }

    return s;
  }
};


// test
int main() {
  Solution solution;

  cout << solution.reverseStr("1112223334", 4) << endl;

  return 0;
}


