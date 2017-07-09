/*
 * https://leetcode.com/problems/roman-to-integer/#/description
 *
 * Given a roman numeral, convert it to an integer.
 * Input is guaranteed to be within the range from 1 to 3999.
 *
 */

#include <iostream>
#include <map>
#include <string>
using namespace std;


// solution 1
class Solution {
public:
  int romanToInt(string s) {
    map<char, int> DIC;
    DIC['I'] = 1;
    DIC['V'] = 5;
    DIC['X'] = 10;
    DIC['L'] = 50;
    DIC['C'] = 100;
    DIC['D'] = 500;
    DIC['M'] = 1000;

    int result = 0;
    for (int i = 0; i < s.size() - 1; i++) {
      int current = DIC[s[i]];
      int next = DIC[s[i + 1]];

      if (current >= next) result += current;
      else result -= current;
    }

    return result + DIC[s[s.size() - 1]];
  }
};


// test
int main() {
  Solution solution;

  cout << solution.romanToInt("IV") << endl;

  return 0;
}


