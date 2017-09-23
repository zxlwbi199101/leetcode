/*
 * https://leetcode.com/problems/word-search/description/
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring.
 * The same letter cell may not be used more than once.
 *
 * For example,
 * Given board =
 *
 * [
 *   ['A','B','C','E'],
 *   ['S','F','C','S'],
 *   ['A','D','E','E']
 * ]
 * word = "ABCCED", -> returns true,
 * word = "SEE", -> returns true,
 * word = "ABCB", -> returns false.
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
  bool exist(vector<vector<char>>& board, string word) {
    if (!board.size() || !board[0].size()) return false;

    for (int x = 0; x < board.size(); ++x) {
      for (int y = 0; y < board[0].size(); ++y) {
        if (board[x][y] == word[0] && check(board, x, y, word, 0)) return true;
      }
    }

    return false;
  }

  bool check(vector<vector<char>> &board, int x, int y, string word, int index) {
    if (x >= board.size() || y >= board[0].size() || x < 0 || y < 0) {
      return false;
    }

    if (word[index] == board[x][y]) {
      if (word.size() == index + 1) return true;
      index++;

      char cache = board[x][y];
      board[x][y] = '^';
      bool ret = check(board, x + 1, y, word, index)
      || check(board, x - 1, y, word, index)
      || check(board, x, y - 1, word, index)
      || check(board, x, y + 1, word, index);
      board[x][y] = cache;

      return ret;
    }

    return false;
  }
};


// test
int main() {
  Solution solution;

  // vector<char> w1 = {'A','B', 'C', 'E'};
  // vector<char> w2 = {'S','F', 'C', 'S'};
  // vector<char> w3 = {'A','D', 'E', 'E'};
  // vector<vector<char>> w = {w1,w2,w3};

  // cout << solution.exist(w, "ABCCED") << endl;



  vector<char> w1 = {'A','A'};
  vector<vector<char>> w = {w1};

  cout << solution.exist(w, "AAA") << endl;
  return 0;
}

