/*
 * https://leetcode.com/problems/word-pattern/discuss/
 *
 * Given a pattern and a string str, find if str follows the same pattern.
 *
 * Here follow means a full match, such that there is a bijection between a
 * letter in pattern and a non-empty word in str.
 *
 * Examples:
 * pattern = "abba", str = "dog cat cat dog" should return true.
 * pattern = "abba", str = "dog cat cat fish" should return false.
 * pattern = "aaaa", str = "dog cat cat dog" should return false.
 * pattern = "abba", str = "dog dog dog dog" should return false.
 * Notes:
 * You may assume pattern contains only lowercase letters, and str contains
 * lowercase letters separated by a single space.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

// solution 1
class Solution {
public:
  bool wordPattern(string pattern, string str) {
    unordered_map<char, string> m;
    unordered_map<string, char> mr;

    int cur = 0;
    for (int i = 0; i < str.size(); i++, cur++) {
      for (; str[i] == ' '; i++) {} // skip all spaces
      int start = i;
      for (; i < str.size() && str[i] != ' '; i++) {}
      string word = str.substr(start, i - start);

      if (cur >= pattern.size()) return false;
      if (m.find(pattern[cur]) != m.end()) {
        if (word != m[pattern[cur]]) return false;
      } else {
        if (mr.find(word) != mr.end()) return false;
        m[pattern[cur]] = word;
        mr[word] = pattern[cur];
      }
    }

    return cur == pattern.size();
  }
};


// test
int main() {
  Solution solution;
  cout << solution.wordPattern("abba", "dog cat cat dog") << endl;
  return 0;
}


