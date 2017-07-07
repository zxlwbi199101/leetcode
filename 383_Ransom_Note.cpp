/*
 * https://leetcode.com/problems/ransom-note/#/description
 *
 * Given an arbitrary ransom note string and another string containing
 * letters from all the magazines, write a function that will return true
 * if the ransom note can be constructed from the magazines ; otherwise,
 * it will return false.
 *
 * Each letter in the magazine string can only be used once in your ransom note.
 *
 */

#include <iostream>
#include <vector>
using namespace std;

// solution 1
class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    int word[26];
    for (int i = 0; i < 26; i++) word[i] = 0;

    for (char c : ransomNote) word[c - 'a']++;
    for (char c : magazine) word[c - 'a']--;

    for (int i : word) {
      if (i > 0) return false;
    }
    return true;
  }
};


// test
int main() {
  Solution solution;
  string s1 = "aa";
  string s2 = "aab";

  cout << solution.canConstruct(s1, s2) << endl;

  return 0;
}


