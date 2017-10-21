/*
 * https://leetcode.com/problems/map-sum-pairs/description/
 *
 * Implement a MapSum class with insert, and sum methods.
 *
 * For the method insert, you'll be given a pair of (string, integer). The string
 * represents the key and the integer represents the value. If the key already
 * existed, then the original key-value pair will be overridden to the new one.
 *
 * For the method sum, you'll be given a string representing the prefix, and you
 * need to return the sum of all the pairs' value whose key starts with the prefix.
 *
 * Example 1:
 * Input: insert("apple", 3), Output: Null
 * Input: sum("ap"), Output: 3
 * Input: insert("app", 2), Output: Null
 * Input: sum("ap"), Output: 5
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

struct TrieNode {
  int val;
  TrieNode* children[26];
  TrieNode(int x) : val(x) {
    memset(children, NULL, sizeof(children));
  }
};

class MapSum {
public:
  TrieNode* root;

  /** Initialize your data structure here. */
  MapSum() {
    root = new TrieNode(0);
  }

  void insert(string key, int val) {
    TrieNode* cur = root;

    for (char c : key) {
      int i = c - 'a';

      if (!cur->children[i]) {
        cur->children[i] = new TrieNode(0);
      }

      cur = cur->children[i];
    }

    cur->val = val;
  }

  int sum(string prefix) {
    TrieNode* cur = root;

    for (char c : prefix) {
      cur = cur->children[c - 'a'];
      if (!cur) return 0;
    }

    return recursive(cur);
  }

  int recursive(TrieNode* node) {
    int result = node->val;

    for (int i = 0; i < 26; i++) {
      if ((node->children)[i]) {
        result += recursive((node->children)[i]);
      }
    }

    return result;
  }
};


// test case
int main() {
  return 0;
}
