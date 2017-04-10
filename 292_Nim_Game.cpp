/*
 * https://leetcode.com/problems/nim-game/#/description
 *
 * You are playing the following Nim Game with your friend:
 * There is a heap of stones on the table, each time one of you take turns to
 * remove 1 to 3 stones. The one who removes the last stone will be the winner.
 * You will take the first turn to remove the stones.
 * Both of you are very clever and have optimal strategies for the game.
 * Write a function to determine whether you can win the game given the number of
 * stones in the heap.
 *
 * For example, if there are 4 stones in the heap, then you will never
 * win the game: no matter 1, 2, or 3 stones you remove, the last stone will always
 * be removed by your friend.
 *
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;


// solution 1
class Solution {
public:
  bool canWinNim(int n) {
    return n % 4;
  }
};


// test
int main() {
  Solution solution;

  cout << solution.canWinNim(1) << endl;
  cout << solution.canWinNim(2) << endl;
  cout << solution.canWinNim(3) << endl;
  cout << solution.canWinNim(4) << endl;
  cout << solution.canWinNim(5) << endl;
  cout << solution.canWinNim(6) << endl;
  cout << solution.canWinNim(7) << endl;
  cout << solution.canWinNim(8) << endl;
  cout << solution.canWinNim(9) << endl;
  cout << solution.canWinNim(10) << endl;

  return 0;
}


