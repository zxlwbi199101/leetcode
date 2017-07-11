/*
 * https://leetcode.com/problems/binary-watch/#/description
 *
 * A binary watch has 4 LEDs on the top which represent the hours (0-11),
 * and the 6 LEDs on the bottom represent the minutes (0-59).
 *
 * Each LED represents a zero or one, with the least significant bit on the right.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <bitset>
using namespace std;

// solution 1
class Solution {
public:
  vector<string> readBinaryWatch(int num) {
    vector<string> result;
    int temp;

    map<int, vector<int>> hourMap;
    hourMap[0] = vector<int> {0};
    hourMap[1] = vector<int> {1,2,4,8};
    hourMap[2] = vector<int> {3,5,9,6,10};
    hourMap[3] = vector<int> {7,11};

    map<int, vector<int>> minuteMap;
    minuteMap[0] = vector<int> {0};

    for (int i = 1; i < 60; i++) {
      temp = bitset<10>(i).count();

      if (minuteMap.find(temp) == minuteMap.end()) {
        minuteMap[temp] = vector<int> {i};
      } else {
        minuteMap[temp].push_back(i);
      }
    }
    // for (int i : minuteMap[1]) cout << i << endl;
    for (int i = 0; i <= 3 && i <= num; i++) {
      vector<int> hours = hourMap[i];
      vector<int> minutes = minuteMap[num - i];

      for (int h : hours) {
        for (int m : minutes) {
          string mStr = (m < 10 ? "0" : "") + to_string(m);
          result.push_back(to_string(h) + ":" + mStr);
        }
      }
    }

    return result;
  }
};


// test
int main() {
  Solution solution;

  vector<string> result = solution.readBinaryWatch(1);
  for (string s : result) cout << s << endl;

  return 0;
}


