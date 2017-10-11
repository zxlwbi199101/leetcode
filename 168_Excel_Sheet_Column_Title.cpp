/*
 * https://leetcode.com/problems/excel-sheet-column-title/description/
 *
 * Given a positive integer, return its corresponding column title as appear
 * in an Excel sheet.
 *
 * For example:
 *
 *     1 -> A
 *     2 -> B
 *     3 -> C
 *     ...
 *     26 -> Z
 *     27 -> AA
 *     28 -> AB
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <math.h>
#include <ctype.h>
using namespace std;

// solution 1
class Solution {
public:
  string convertToTitle(int n) {
    string result = "";
    while (n > 0) {
      result = char('A' + (n - 1) % 26) + result;
      n = (n - 1) / 26;
    }

    return result;
  }
};

// test
int main() {
  Solution solution;
  cout << solution.convertToTitle(26) << endl;

  return 0;
}



