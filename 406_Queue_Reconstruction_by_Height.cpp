/*
 * https://leetcode.com/problems/queue-reconstruction-by-height/description/
 *
 * Suppose you have a random list of people standing in a queue. Each person
 * is described by a pair of integers (h, k), where h is the height of the
 * person and k is the number of people in front of this person who have a
 * height greater than or equal to h. Write an algorithm to reconstruct the
 * queue.
 *
 * Note:
 * The number of people is less than 1,100.
 *
 * Example
 *
 * Input:
 * [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
 *
 * Output:
 * [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <list>
#include <queue>
#include <math.h>
#include <ctype.h>
using namespace std;

// solution 1
class Solution {
public:
  vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
    sort(people.begin(), people.end(), [](pair<int, int> a, pair<int, int>b) {
      if (a.first == b.first) return a.second < b.second;
      return a.first > b.first;
    });

    list<pair<int, int>> l;

    for (int i = 0; i < people.size(); i++) {
      auto it = l.begin();
      for (int j = 0; j < people[i].second; j++) it++;
      l.emplace(it, people[i]);
    }

    vector<pair<int, int>> result(l.begin(), l.end());

    return result;
  }
};


// test case
int main() {
  return 0;
}
