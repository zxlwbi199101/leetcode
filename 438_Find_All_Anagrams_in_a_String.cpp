/*
 * https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
 *
 * Given a string s and a non-empty string p, find all the start indices of
 * p's anagrams in s.
 *
 * Strings consists of lowercase English letters only and the length of both
 * strings s and p will not be larger than 20,100.
 *
 * The order of output does not matter.
 *
 * Example 1:
 *
 * Input:
 * s: "cbaebabacd" p: "abc"
 *
 * Output:
 * [0, 6]
 *
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of "abc".
 * Example 2:
 *
 * Input:
 * s: "abab" p: "ab"
 *
 * Output:
 * [0, 1, 2]
 *
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab".
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

// solution 1
class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> result;

    int hash[256] = {0};
    int count = p.size(), left = 0, right = 0;

    for (char c : p) hash[c]++;
    while (right < s.size()) {
      if (hash[s[right++]]-- > 0) count--;
      if (!count) result.push_back(left);
      if (right - left == p.size()) {
        if (hash[s[left++]]++ >= 0) count++;
      }
    }

    return result;
  }
};


// test
int main() {
  Solution solution;
  for (int i : solution.findAnagrams("cbaebabacd", "abc")) cout << i << endl;
  return 0;
}


