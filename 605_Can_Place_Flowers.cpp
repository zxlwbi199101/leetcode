/*
 * https://leetcode.com/problems/can-place-flowers/description/
 *
 * Suppose you have a long flowerbed in which some of the plots are
 * planted and some are not. However, flowers cannot be planted in adjacent
 * plots - they would compete for water and both would die.
 *
 * Given a flowerbed (represented as an array containing 0 and 1, where 0
 * means empty and 1 means not empty), and a number n, return if n new flowers
 * can be planted in it without violating the no-adjacent-flowers rule.
 *
 */

#include <iostream>
#include <set>
#include <vector>
using namespace std;


// solution 1
class Solution {
public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int sum = 0;
    int len = flowerbed.size();

    flowerbed.push_back(0);
    flowerbed.insert(flowerbed.begin(),0);

    for (int i = 1; i <= len && sum <= n; i++) {
      if (flowerbed[i] == 0 && flowerbed[i + 1] == 0 && flowerbed[i - 1] == 0) {
        sum++;
        flowerbed[i] = 1;
      }
    }

    return sum >= n;
  }
};


// test
int main() {
  Solution solution;

  vector<int> v1 = {1,0,0,0,1,0,0};

  cout << solution.canPlaceFlowers(v1, 2) << endl;

  return 0;
}


