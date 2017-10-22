/*
 * https://leetcode.com/problems/implement-magic-dictionary/description/
 *
 * Implement a magic directory with buildDict, and search methods.
 *
 * For the method buildDict, you'll be given a list of non-repetitive words to
 * build a dictionary.
 *
 * For the method search, you'll be given a word, and judge whether if you modify
 * exactly one character into another character in this word, the modified word is
 * in the dictionary you just built.
 *
 * Example 1:
 * Input: buildDict(["hello", "leetcode"]), Output: Null
 * Input: search("hello"), Output: False
 * Input: search("hhllo"), Output: True
 * Input: search("hell"), Output: False
 * Input: search("leetcoded"), Output: False
 * Note:
 * You may assume that all the inputs are consist of lowercase letters a-z.
 * For contest purpose, the test data is rather small by now. You could think about
 * highly efficient algorithm after the contest.
 * Please remember to RESET your class variables declared in class MagicDictionary,
 * as static/class variables are persisted across multiple test cases. Please see
 * here for more details.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <list>
#include <queue>
#include <math.h>
#include <ctype.h>
using namespace std;

class MagicDictionary {
public:
  unordered_map<string, unordered_set<char>> hash;

  /** Initialize your data structure here. */
  MagicDictionary() {
  }

  /** Build a dictionary through a list of words */
  void buildDict(vector<string> dict) {
    for (string s : dict) {
      for (int i = 0; i < s.size(); i++) {
        char temp = s[i];
        s[i] = '_';

        if (hash.find(s) == hash.end()) {
          hash[s] = {temp};
        } else {
          hash[s].insert(temp);
        }

        s[i] = temp;
      }
    }
  }

  /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
  bool search(string word) {
    for (int i = 0; i < word.size(); i++) {
      char temp = word[i];
      word[i] = '_';

      if (hash.find(word) != hash.end()) {
        auto h = hash[word];

        if (h.size() > 1 || h.find(temp) == h.end()) {
          return true;
        }
      }
      word[i] = temp;
    }

    return false;
  }
};


// test case
int main() {
  return 0;
}
