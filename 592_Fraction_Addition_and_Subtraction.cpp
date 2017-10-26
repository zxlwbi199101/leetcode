/*
 * https://leetcode.com/problems/fraction-addition-and-subtraction/description/
 *
 * Given a string representing an expression of fraction addition and subtraction,
 * you need to return the calculation result in string format. The final result
 * should be irreducible fraction. If your final result is an integer, say 2, you
 * need to change it to the format of fraction that has denominator 1. So in this
 * case, 2 should be converted to 2/1.
 *
 * Example 1:
 * Input:"-1/2+1/2"
 * Output: "0/1"
 * Example 2:
 * Input:"-1/2+1/2+1/3"
 * Output: "1/3"
 * Example 3:
 * Input:"1/3-1/2"
 * Output: "-1/6"
 * Example 4:
 * Input:"5/3+1/3"
 * Output: "2/1"
 * Note:
 * The input string only contains '0' to '9', '/', '+' and '-'. So does the output.
 * Each fraction (input and output) has format ±numerator/denominator. If the
 * first input fraction or the output is positive, then '+' will be omitted.
 * The input only contains valid irreducible fractions, where the numerator and
 * denominator of each fraction will always be in the range [1,10]. If the
 * denominator is 1, it means this fraction is actually an integer in a fraction format defined above.
 * The number of given fractions will be in the range [1,10].
 * The numerator and denominator of the final result are guaranteed to be valid
 * and in the range of 32-bit int.
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
#include <regex>
#include <stdlib.h>

using namespace std;

// solution 1
class Solution {
public:
  string fractionAddition(string expression) {
    smatch m;
    regex e ("([+-]?)(\\d+)/(\\d+)");

    int lastDenominator = 1, lastNumerator = 0;
    int curDenominator = 1, curNumerator = 0;

    for (string s = expression; regex_search(s, m, e); s = m.suffix().str()) {
      bool negative = m[1].str() == "-";
      curNumerator = atoi(m[2].str().c_str()) * (negative ? -1 : 1);
      curDenominator = atoi(m[3].str().c_str());

      add(lastDenominator, lastNumerator, curDenominator, curNumerator);
    }

    return to_string(lastNumerator) + "/" + to_string(lastDenominator);
  }

  void add(int& ld, int& ln, int& cd, int& cn) {
    int g = gcd(abs(ld), abs(cd)); // gcd
    int l = ld / g * cd; // lcm

    ln = l / ld * ln + l / cd * cn;
    ld = l;

    g = gcd(abs(ld), abs(ln));
    ln /= g;
    ld /= g;
  }

  int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
  }
};

// test
int main() {
  Solution solution;
  solution.fractionAddition("-1/2+1/2+1/3");
  return 0;
}



