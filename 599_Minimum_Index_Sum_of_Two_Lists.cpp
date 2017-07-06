/*
 * https://leetcode.com/problems/minimum-index-sum-of-two-lists/#/description
 *
 * Suppose Andy and Doris want to choose a restaurant for dinner, and
 * they both have a list of favorite restaurants represented by strings.
 *
 * You need to help them find out their common interest with the least list
 * index sum. If there is a choice tie between answers, output all of them
 * with no order requirement. You could assume there always exists an answer.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// solution 1
class Solution {
public:
  vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    vector<string> result;
    int minSum = INT_MAX;

    map<string, int> indexMap;
    string temp;
    int tempIndex;

    for (int i = 0; i < list1.size(); i++) indexMap[list1[i]] = i;

    for (int i = 0; i < list2.size(); i++) {
      string temp = list2[i];

      if (indexMap.find(temp) != indexMap.end()) {
        tempIndex = indexMap[temp];

        if (tempIndex + i < minSum) {
          minSum = tempIndex + i;
          result.clear();
          result.push_back(temp);
        } else if (tempIndex + i == minSum) {
          result.push_back(temp);
        }
      }
    }

    return result;
  }
};


// test
int main() {
  Solution solution;
  vector<string> v1 = {"Shogun","Tapioca Express","Burger King","KFC"};
  vector<string> v2 = {"KFC","Burger King","Tapioca Express","Shogun"};

  vector<string> result = solution.findRestaurant(v1, v2);

  for (string s : result) cout << s << endl;

  return 0;
}


