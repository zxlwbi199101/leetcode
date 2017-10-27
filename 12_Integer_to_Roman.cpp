/*
 * https://leetcode.com/problems/integer-to-roman/description/
 *
 * Given an integer, convert it to a roman numeral.
 *
 * nput is guaranteed to be within the range from 1 to 3999.
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
  string intToRoman(int num) {
    vector<vector<string>> dict = {
      {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
      {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
      {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
      {"", "M", "MM", "MMM"}
    };

    string result = dict[3][num / 1000];
    num %= 1000;
    result += dict[2][num / 100];
    num %= 100;
    result += dict[1][num / 10];
    num %= 10;
    return result + dict[0][num];
  }
};

// test
int main() {
  return 0;
}



