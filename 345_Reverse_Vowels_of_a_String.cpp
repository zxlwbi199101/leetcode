/*
 * https://leetcode.com/problems/reverse-vowels-of-a-string/description/
 *
 * Write a function that takes a string as input and reverse only the vowels
 * of a string.
 *
 * Example 1:
 * Given s = "hello", return "holle".
 *
 * Example 2:
 * Given s = "leetcode", return "leotcede".
 *
 * Note:
 * The vowels does not include the letter "y".
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
  string reverseVowels(string s) {
    int i = 0, j = s.size() - 1;
    const string vowels = "aeiouAEIOU";

    while (i < j) {
      bool left = vowels.find(s[i]) != string::npos;
      bool right = vowels.find(s[j]) != string::npos;

      if (left && right) {
        swap(s[i], s[j]);
        i++, j--;
      }
      if (!left) i++;
      if (!right) j--;
    }

    return s;
  }
};

// test
int main() {
  Solution solution;
  cout << solution.reverseVowels("Hello") << endl;

  return 0;
}



