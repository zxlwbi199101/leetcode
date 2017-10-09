/*
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word in the string.
 *
 * If the last word does not exist, return 0.
 *
 * Note: A word is defined as a character sequence consists of non-space
 * characters only.
 *
 * For example,
 * Given s = "Hello World",
 * return 5.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <math.h>
#include <ctype.h>
using namespace std;

// solution 1
class Solution {
public:
  int lengthOfLastWord(string s) {
    int len = 0;
    bool entered = false;

    for (int i = s.size() - 1; i >= 0; i--) {
      if (isspace(s[i])){
        if (entered) return len;
      } else {
        entered = true;
        len++;
      }
    }

    return len;
  }
};

// test
int main() {
  Solution solution;
  cout << solution.lengthOfLastWord("Hello, my name is John") << endl;

  return 0;
}



