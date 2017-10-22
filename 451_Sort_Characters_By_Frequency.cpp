/*
 * https://leetcode.com/problems/sort-characters-by-frequency/description/
 *
 * Given a string, sort it in decreasing order based on the frequency of characters.
 *
 * Example 1:
 *
 * Input:
 * "tree"
 *
 * Output:
 * "eert"
 *
 * Explanation:
 * 'e' appears twice while 'r' and 't' both appear once.
 * So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
 * Example 2:
 *
 * Input:
 * "cccaaa"
 *
 * Output:
 * "cccaaa"
 *
 * Explanation:
 * Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
 * Note that "cacaca" is incorrect, as the same characters must be together.
 * Example 3:
 *
 * Input:
 * "Aabb"
 *
 * Output:
 * "bbAa"
 *
 * Explanation:
 * "bbaA" is also a valid answer, but "Aabb" is incorrect.
 * Note that 'A' and 'a' are treated as two different characters.
 *
 */

#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

// solution 1
class Solution {
public:
  string frequencySort(string s) {
    unordered_map<char, int> m;
    for (char c : s) m[c]++;

    vector<pair<char, int>> elems(m.begin(), m.end());
    sort(elems.begin(), elems.end(), [](pair<char, int> a, pair<char, int> b) {
      return a.second > b.second;
    });

    string result = "";
    for (auto e : elems) {
      for (int i = 0; i < e.second; i++) result += e.first;
    }
    return result;
  }
};


// test
int main() {
  return 0;
}


