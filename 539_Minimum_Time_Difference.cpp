/*
 * https://leetcode.com/problems/minimum-time-difference/description/
 *
 * Given a list of 24-hour clock time points in "Hour:Minutes" format, find
 * the minimum minutes difference between any two time points in the list.
 *
 * Example 1:
 * Input: ["23:59","00:00"]
 * Output: 1
 * Note:
 * The number of time points in the given list is at least 2 and won't exceed 20000.
 * The input time is legal and ranges from 00:00 to 23:59.
 *
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

// solution 1
class Solution {
public:
  int findMinDifference(vector<string>& timePoints) {
    vector<bool> bucket(24 * 60, false);

    int minTime = INT_MAX;
    for (string s : timePoints) {
      int minutes = (s[0] - '0') * 10 * 60 +
                    (s[1] - '0') * 60 +
                    (s[3] - '0') * 10 +
                    (s[4] - '0');

      minTime = min(minTime, minutes);
      if (bucket[minutes]) return 0;
      bucket[minutes] = true;
    }

    int m = INT_MAX, last = minTime;
    for (int i = minTime + 1; i < bucket.size(); i++) {
      if (!bucket[i]) continue;

      m = min(m, i - last);
      last = i;
    }

    m = min(m, minTime - last + 1440);
    return m;
  }
};


// test
int main() {
  return 0;
}

