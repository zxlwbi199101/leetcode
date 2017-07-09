/*
 * https://leetcode.com/problems/valid-anagram/#/solutions
 *
 * Given two strings s and t, write a function to determine if t is an anagram of s.
 *
 * For example,
 * s = "anagram", t = "nagaram", return true.
 * s = "rat", t = "car", return false.
 *
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;


// solution 1
class Solution {
public:
  bool isAnagram(string s, string t) {
    int word[26] = {0};

    for (char c : s) word[c - 'a']++;
    for (char c : t) {
      word[c - 'a']--;
      if (word[c - 'a'] < 0) return false;
    }
    for (int i : word) {
      if (i != 0) return false;
    }

    return true;
  }
};


// test
int main() {
  Solution solution;

  cout << solution.isAnagram("anagram", "nagaram") << endl;
  cout << solution.isAnagram("rat", "car") << endl;
  cout << solution.isAnagram("a", "b") << endl;

  return 0;
}


