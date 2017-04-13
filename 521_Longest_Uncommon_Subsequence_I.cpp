/*
 * https://leetcode.com/problems/longest-uncommon-subsequence-i/#/description
 *
 * Given a group of two strings, you need to find the longest uncommon subsequence
 *  of this group of two strings. The longest uncommon subsequence is defined as the
 * longest subsequence of one of these strings and this subsequence should not be any
 * subsequence of the other strings.
 *
 * A subsequence is a sequence that can be derived from one sequence by deleting some
 * characters without changing the order of the remaining elements. Trivially, any string
 * is a subsequence of itself and an empty string is a subsequence of any string.
 *
 * The input will be two strings, and the output needs to be the length of the longest
 * uncommon subsequence. If the longest uncommon subsequence doesn't exist, return -1.
 *
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


// solution 1
class Solution {
public:
  int findLUSlength(string a, string b) {
    if (a == b) return -1;
    return max(a.size(), b.size());
  }
};


// test
int main() {
  Solution solution;

  cout << solution.findLUSlength("google", "asdf") << endl;
  cout << solution.findLUSlength("asdf", "asdf") << endl;

  return 0;
}


