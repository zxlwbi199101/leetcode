/*
 * https://leetcode.com/problems/longest-palindrome/#/description
 *
 * Given a string which consists of lowercase or uppercase letters,
 * find the length of the longest palindromes that can be built with those letters.
 *
 * This is case sensitive, for example "Aa" is not considered a palindrome here.
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
  int longestPalindrome(string s) {
    if (s.size() == 0) return 0;
    if (s.size() == 1) return 1;

    int word[58] = {0};
    int sum = 0;
    bool hasSingle = false;

    for (char c : s) word[c - 'A']++;
    for (int w : word) {
      if (w % 2 > 0) hasSingle = true;
      sum += w / 2 * 2;
    }

    return sum + (hasSingle ? 1 : 0);
  }
};


// test
int main() {
  Solution solution;

  cout << solution.longestPalindrome("abccccdd") << endl;

  return 0;
}


