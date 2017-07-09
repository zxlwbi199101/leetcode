/*
 * https://leetcode.com/problems/first-unique-character-in-a-string/#/description
 *
 * Given a string, find the first non-repeating character in it and return it's index.
 * If it doesn't exist, return -1.
 *
 */

#include <iostream>
#include <string>
#include <map>
using namespace std;

// solution 1
class Solution {
public:
  int firstUniqChar(string s) {
    map<char, pair<int, int>> m;
    int index = INT_MAX;

    for (int i = 0; i < s.size(); i++) {
      char c = s[i];
      if (m.find(c) != m.end()) {
        (m[c].second)++;
      } else m[c] = make_pair(i, 1);
    }

    for (pair<char, pair<int, int>> p : m) {
      if (p.second.second == 1 && p.second.first < index) {
        index = p.second.first;
      }
    }

    return index == INT_MAX ? -1 : index;
  }
};


// test
int main() {
  Solution solution;

  cout << solution.firstUniqChar("loveleetcode") << endl;

  return 0;
}


