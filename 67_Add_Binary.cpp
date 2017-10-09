/*
 * https://leetcode.com/problems/add-binary/description/
 *
 * Given two binary strings, return their sum (also a binary string).
 *
 * For example,
 * a = "11"
 * b = "1"
 * Return "100".
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
  string addBinary(string a, string b) {
    bool carry = false;
    int i = a.size() - 1, j = b.size() - 1;
    string result = "";

    while (i >= 0 || j >= 0) {
      char l = i < 0 ? '0' : a[i];
      char r = j < 0 ? '0' : b[j];
      char res = '0';

      if (l == '1' && r == '1') {
        res = carry ? '1' : '0';
        carry = true;
      } else if (l == '0' && r == '0') {
        res = carry ? '1' : '0';
        carry = false;
      } else {
        res = carry ? '0' : '1';
      }

      result = res + result;
      i--, j--;
    }

    return carry ? ('1' + result) : result;
  }
};

// test
int main() {
  Solution solution;
  cout << solution.addBinary("1", "11") << endl;

  return 0;
}



