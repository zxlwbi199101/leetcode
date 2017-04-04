/*
 * https://leetcode.com/problems/reverse-string/#/description
 *
 * Write a function that takes a string as input and returns the string reversed.
 * Example:
 * Given s = "hello", return "olleh".
 *
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;


// solution 1
class Solution {
public:
  string reverseString(string s) {
    for (int i = 0, sz = s.size(); i < sz; i++) {
      swap(s[i], s[--sz]);
    }

    return s;
  }
};


// test
int main() {
  Solution solution;
  cout << solution.reverseString("hell") << endl;
  cout << solution.reverseString("hello") << endl;
  cout << solution.reverseString("QZrD2 7UL91z,i`O2ef:6e'2\"yP !:,U.:pX90PU3CXo'i!;3 `j 0?\"'hK8 ? BAjM2\"DBw?7!4R3?U2E8F2y!?3 R2!fw 6e!:0  ErCi98KM`,8`8648,mi3P0`,!5 E.?00J3A 52\"x8,tHy!'2!DJBbK'j!tt1C' 7`JPulW\"\"uRTbr\"',\",U`ZOW5'\"JMDQDML\"'5WOZ`U,\",'\"rbTRu\"\"WluPJ`7 'C1tt!j'KbBLD!2'!yHt,8x\"25 A3J00?.E 5!,`0P3im,8468`8,`MK89iCrE  0:!e6 wf!2R 3?!y2F8E2U?3R4!7?wBD\"2MjAB ? 8Kh'\"?0 j` 3;!i'oXC3UP09Xp:.U,:! Py\"2'e6:fe2O`i,z19LU7 2DrZQ") << endl;

  return 0;
}
