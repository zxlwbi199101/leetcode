/*
 * https://leetcode.com/problems/valid-palindrome-ii/description/
 *
 * Given a non-empty string s, you may delete at most one character. Judge
 * whether you can make it a palindrome.
 *
 * Example 1:
 * Input: "aba"
 * Output: True
 * Example 2:
 * Input: "abca"
 * Output: True
 * Explanation: You could delete the character 'c'.
 * Note:
 * The string will only contain lowercase characters a-z. The maximum length
 * of the string is 50000.
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
  bool validPalindrome(string s) {
    int front = 0, end = s.size() - 1;
    short deleted = 0; // 1: from front, 2: from end, 0: not set
    int misIndex = -1;

    while (front < end) {
      if (s[front] == s[end]) {
        front++;
        end--;
      } else if (!deleted) { // first mismatch
        misIndex = front;
        front++;
        deleted = 1;
      } else if (deleted == 1) {
        front = misIndex;
        end = s.size() - misIndex - 2;
        deleted = 2;
      } else return false;
    }

    return true;
  }
};

// test
int main() {
  Solution solution;
  cout << solution.validPalindrome("abcsa") << endl;

  return 0;
}



