/*
 * https://leetcode.com/problems/queue-reconstruction-by-height/description/
 *
 * Given a string, your task is to count how many palindromic substrings in
 * this string.
 *
 * The substrings with different start indexes or end indexes are counted as
 * different substrings even they consist of same characters.
 *
 * Example 1:
 * Input: "abc"
 * Output: 3
 * Explanation: Three palindromic strings: "a", "b", "c".
 * Example 2:
 * Input: "aaa"
 * Output: 6
 * Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 * Note:
 * The input string length won't exceed 1000.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <list>
#include <queue>
#include <math.h>
#include <ctype.h>
using namespace std;

// solution 1
class Solution {
public:
  int countSubstrings(string s) {
    if (s.size() == 1) return 1;
    int result = 0;

    vector<int> manacher (2001);
    int maxRight = 0, maxCenter = 0;

    // fake "1234" to "#1#2#3#4" for manacher algorithm
    for (int i = 0; i < s.size() * 2; i++) {
      if (maxRight > i) {
        manacher[i] = min(manacher[2 * maxCenter - i], maxRight - i);
      }

      while (manacher[i] + i < s.size() * 2 && i - manacher[i] > 0) {
        int r = manacher[i] + i + 1, l = i - manacher[i] - 1;

        if (r % 2 == 0) {
          manacher[i]++;
          continue;
        }
        if (s[r / 2] == s[l / 2]) manacher[i]++;
        else break;
      }

      if (maxRight < manacher[i] + i) {
        maxRight = manacher[i] + i;
        maxCenter = i;
      }

      result += (manacher[i] + 1) / 2;
    }

    return result;
  }
};


// test case
int main() {
  Solution solution;
  cout << solution.countSubstrings("aaaaa") << endl;

  return 0;
}
