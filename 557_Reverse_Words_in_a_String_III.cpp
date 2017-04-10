/*
 * https://leetcode.com/problems/reverse-words-in-a-string-iii/#/description
 *
 * Given a string, you need to reverse the order of characters in each word
 * within a sentence while still preserving whitespace and initial word order.
 *
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;


// solution 1
class Solution {
public:
  string reverseWords(string s) {
    int lastSpacePos = -1;
    char temp;
    int from, to;

    for (int i = 0, size = s.size(); i < size; i++) {
      if (s[i] != ' ' && i != size - 1) continue;

      from = lastSpacePos + 1;
      to = i == size - 1 ? i : i - 1;

      for (int j = from; j < (from + to + 1) / 2; j++) {
        temp = s[j];
        s[j] = s[to - (j - from)];
        s[to - (j - from)] = temp;
      }

      lastSpacePos = i;
    }

    return s;
  }
};


// test
int main() {
  Solution solution;

  cout << solution.reverseWords("Let's take LeetCode contest") << endl;

  return 0;
}


