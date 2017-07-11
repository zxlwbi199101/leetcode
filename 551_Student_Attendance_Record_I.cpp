/*
 * https://leetcode.com/problems/student-attendance-record-i/#/description
 *
 * You are given a string representing an attendance record for a student.
 * The record only contains the following three characters:
 *
 * 'A' : Absent.
 * 'L' : Late.
 * 'P' : Present.
 * A student could be rewarded if his attendance record doesn't contain more than
 * one 'A' (absent) or more than two continuous 'L' (late).
 *
 * You need to return whether the student could be rewarded according to his attendance record.
 *
 */

#include <iostream>
#include <vector>
#include <map>
#include <math.h>
using namespace std;

// solution 1
class Solution {
public:
  bool checkRecord(string s) {
    int absent = 0;
    int late = 0;
    bool keepLate = false;

    for (char c : s) {
      if (c == 'A') absent++;
      if (c == 'L') {
        if (keepLate) late++;
        else {
          late = 1;
          keepLate = true;
        }
      } else {
        keepLate = false;
      }

      if (late > 2 || absent > 1) return false;
    }

    return true;
  }
};


// test
int main() {
  Solution solution;

  cout << solution.checkRecord("LALL") << endl;

  return 0;
}


