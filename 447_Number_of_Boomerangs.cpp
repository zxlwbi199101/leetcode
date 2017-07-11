/*
 * https://leetcode.com/problems/number-of-boomerangs/#/solutions
 *
 * Given n points in the plane that are all pairwise distinct, a "boomerang"
 * is a tuple of points (i, j, k) such that the distance between i and j equals
 * the distance between i and k (the order of the tuple matters).
 *
 * Find the number of boomerangs. You may assume that n will be at most 500 and
 * coordinates of points are all in the range [-10000, 10000] (inclusive).
 *
 */

#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <map>
#include <bitset>
using namespace std;

// solution 1
class Solution {
public:
  int numberOfBoomerangs(vector<pair<int, int>>& points) {
    int sum = 0;
    int distance = 0;
    map<int, int> m;

    for (int i = 0; i < points.size(); i++) {
      m.clear();
      for (int j = 0; j < points.size(); j++) {
        if (i == j) continue;

        distance = pow(points[i].first - points[j].first, 2)
          + pow(points[i].second - points[j].second, 2);

        m[distance]++;
      }

      for (pair<int, int> i : m) {
        sum += i.second * (i.second - 1);
      }
    }

    return sum;
  }
};

// test
int main() {
  Solution solution;

  vector<pair<int, int>> points;
  points.push_back(make_pair(0, 0));
  points.push_back(make_pair(1, 0));
  points.push_back(make_pair(2, 0));

  cout << solution.numberOfBoomerangs(points) << endl;

  return 0;
}

