/*
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * Given a collection of intervals, merge all overlapping intervals.
 *
 * For example,
 * Given [1,3],[2,6],[8,10],[15,18],
 * return [1,6],[8,10],[15,18].
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

// Definition for an interval.
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

// solution 1
class Solution {
public:
  vector<Interval> merge(vector<Interval>& intervals) {
    int len = intervals.size();
    if (len <= 1) return intervals;

    vector<Interval> result(intervals.size());

    int indexl = 0;
    int indexr = 1;
    Interval temp;
    Interval temp1;
    Interval temp2;
    int mergedIndex = 0;

    // do a merge sort here
    for (int chunk = 2; chunk < 2 * len; chunk *= 2) {
      // for each chunk
      for (int i = 0; i < len; i += chunk) {
        indexl = i;
        indexr = i + chunk / 2;
        mergedIndex = i;

        while (true) {
          if ((indexl == i + chunk / 2 || indexl >= len || intervals[indexl].start == INT_MAX ) &&
              (indexr == i + chunk || indexr >= len || intervals[indexr].start == INT_MAX)) {
            break;
          }
          temp1 = intervals[indexl];
          temp2 = intervals[indexr];

          // pick a small one
          if (temp1.start == INT_MAX || indexl == i + chunk / 2 || indexl >= len) {
            indexr++;
            temp = temp2;
          } else if (temp2.start == INT_MAX || indexr == i + chunk || indexr >= len) {
            indexl++;
            temp = temp1;
          } else if (temp1.start > temp2.start) {
            indexr++;
            temp = temp2;
          } else {
            indexl++;
            temp = temp1;
          }

          // merge
          if (mergedIndex > i && result[mergedIndex - 1].end >= temp.start) {
            result[mergedIndex - 1].end = max(temp.end, result[mergedIndex - 1].end);
          } else {
            result[mergedIndex].start = temp.start;
            result[mergedIndex++].end = temp.end;
          }

        } // while end

        if (mergedIndex <= i + chunk - 1 && mergedIndex < len) {
          result[mergedIndex].start = INT_MAX;
        }
      } // for end

      // swap result and intervals
      swap(result, intervals);
    } // for end

    intervals.resize(mergedIndex);
    return intervals;
  }
};

// test
int main() {
  Solution solution;

  vector<Interval> intervals = {
    Interval(3,3),
    Interval(1,1),
    Interval(0,2),
    Interval(2,2),
    Interval(1,2),
    Interval(1,3),
    Interval(1,1),
    Interval(3,3),
    Interval(2,3),
    Interval(4,6)
  };

  vector<Interval> results = solution.merge(intervals);
  for (Interval i : results) {
    cout << i.start << " " << i.end << endl;
  }

  return 0;
}


