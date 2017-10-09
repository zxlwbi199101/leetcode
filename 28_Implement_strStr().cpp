/*
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * Implement strStr().
 *
 * Returns the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <math.h>
using namespace std;

// solution 1
class Solution {
public:
  int strStr(string haystack, string needle) {
    if (needle == "") return 0;
    if (haystack == "") return -1;

    // build prefix table
    vector<int> prefix(needle.size(), 0);
    for (int i = 1, j = 0; i < needle.size(); i++) {
      while (j && needle[i] != needle[j]) j = prefix[j - 1];

      if (needle[i] == needle[j]) j++;
      prefix[i] = j;
    }

    // find the substring
    for (int i = 0, j = 0; i < haystack.size(); i++) {
      while (j && haystack[i] != needle[j])
        j = j ? prefix[j - 1] : 0;

      if (haystack[i] == needle[j]) j++;
      if (j == needle.size()) return i - needle.size() + 1;
    }

    return -1;
  }
};

// test
int main() {
  Solution solution;

  cout << solution.strStr("mississippi", "issip") << endl;

  return 0;
}



