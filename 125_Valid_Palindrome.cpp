/*
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 *
 * For example,
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 *
 * Note:
 * Have you consider that the string might be empty? This is a good question
 * to ask during an interview.
 *
 * For the purpose of this problem, we define empty string as valid palindrome.
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
  bool isPalindrome(string s) {
    int i = 0, j = s.size() - 1;

    while (i < j) {
      int a = normalize(s[i]);
      int b = normalize(s[j]);

      if (a == -1) {
        i++;
        continue;
      }
      if (b == -1) {
        j--;
        continue;
      }

      if (a == b) {
        i++, j--;
      } else {
        return false;
      }
    }

    return true;
  }

  int normalize(char c) {
    if (c >= '0' && c <= '9') return c;
    if (c >= 'a' && c <= 'z') return c - 'a';
    if (c >= 'A' && c <= 'Z') return c - 'A';
    return -1;
  }
};

// test
int main() {
  Solution solution;
  cout << solution.isPalindrome("A man, a plan, a canal: Panama") << endl;

  return 0;
}



