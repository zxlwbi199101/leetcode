/*
 * https://leetcode.com/problems/replace-words/description/
 *
 * In English, we have a concept called root, which can be followed by some
 * other words to form another longer word - let's call this word successor.
 * For example, the root an, followed by other, which can form another word another.
 *
 * Now, given a dictionary consisting of many roots and a sentence. You need to
 * replace all the successor in the sentence with the root forming it. If a
 * successor has many roots can form it, replace it with the root with the shortest length.
 *
 * You need to output the sentence after the replacement.
 *
 * Example 1:
 * Input: dict = ["cat", "bat", "rat"]
 * sentence = "the cattle was rattled by the battery"
 * Output: "the cat was rat by the bat"
 * Note:
 * The input will only have lower-case letters.
 * 1 <= dict words number <= 1000
 * 1 <= sentence words number <= 1000
 * 1 <= root length <= 100
 * 1 <= sentence words length <= 1000
 *
 */

#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

struct TrieNode {
  bool end;
  TrieNode* children[26];
  TrieNode(bool x) : end(x) {
    memset(children, NULL, sizeof(children));
  }
};

// solution 1
class Solution {
public:
  TrieNode* root;

  string replaceWords(vector<string>& dict, string sentence) {
    root = new TrieNode(false);

    for (string s : dict) addToTrie(s);

    string result = "";
    int start = 0;

    while (true) {
      auto pos = sentence.find(' ', start);
      string word = find(
        sentence.substr(
          start,
          (pos == string::npos ?(sentence.size() - start) : (pos - start))
        )
      );

      if (result != "") result += " ";
      result += word;

      if (pos == string::npos) {
        break;
      }
      start = pos + 1;
    }
    cout << result;
    return result;
  }

  string find(string word) {
    TrieNode* cur = root;
    string ret = "";

    for (int i = 0; i < word.size(); i++) {
      int c = word[i] - 'a';
      ret += word[i];

      if (!cur->children[c]) return word;
      if (cur->children[c]->end) return ret;
      cur = cur->children[c];
    }

    return word;
  }

  void addToTrie(string s) {
    TrieNode* cur = root;

    for (int i = 0; i < s.size(); i++) {
      int idx = s[i] - 'a';

      if (!cur->children[idx]) {
        cur->children[idx] = new TrieNode(i == s.size() - 1);
      }
      cur = cur->children[idx];
    }

    cur->end = true;
  }
};


// test
int main() {
  Solution solution;
  vector<string> dict = {
    "cat", "bat", "rat"
  };

  solution.replaceWords(dict, "the cattle was rattled by the battery");

  return 0;
}


