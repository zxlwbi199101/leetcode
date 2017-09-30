/*
 * https://leetcode.com/problems/game-of-life/description/
 *
 * According to the Wikipedia's article: "The Game of Life, also known
 * simply as Life, is a cellular automaton devised by the British mathematician
 * John Horton Conway in 1970."
 *
 * Given a board with m by n cells, each cell has an initial state live (1) or
 * dead (0). Each cell interacts with its eight neighbors (horizontal, vertical,
 * diagonal) using the following four rules (taken from the above Wikipedia
 * article):
 *
 * Any live cell with fewer than two live neighbors dies, as if caused by
 * under-population.
 * Any live cell with two or three live neighbors lives on to the next
 * generation.
 * Any live cell with more than three live neighbors dies, as if by over-
 * population..
 * Any dead cell with exactly three live neighbors becomes a live cell, as
 * if by reproduction.
 * Write a function to compute the next state (after one update) of the board
 * given its current state.
 *
 * Follow up:
 * Could you solve it in-place? Remember that the board needs to be updated at
 * the same time: You cannot update some cells first and then use their updated
 * values to update other cells.
 * In this question, we represent the board using a 2D array. In principle, the
 * board is infinite, which would cause problems when the active area encroaches
 * the border of the array. How would you address these problems?
 * Credits:
 * Special thanks to @jianchao.li.fighter for adding this problem and creating
 * all test cases.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <math.h>
using namespace std;

// solution 1
class Solution {
public:
  void gameOfLife(vector<vector<int>>& board) {
    if (!board.size() || !board[0].size()) return;
    int m = board.size(), n = board[0].size();

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int liveNeighbors = 0;
        if (i && j && abs(board[i - 1][j - 1]) == 1) liveNeighbors++;
        if (i && abs(board[i - 1][j]) == 1) liveNeighbors++;
        if (i && j < n - 1 && abs(board[i - 1][j + 1]) == 1) liveNeighbors++;
        if (j < n - 1 && abs(board[i][j + 1]) == 1) liveNeighbors++;
        if (i < m - 1 && j < n - 1 && abs(board[i + 1][j + 1]) == 1) liveNeighbors++;
        if (i < m - 1 && abs(board[i + 1][j]) == 1) liveNeighbors++;
        if (i < m - 1 && j && abs(board[i + 1][j - 1]) == 1) liveNeighbors++;
        if (j && abs(board[i][j - 1]) == 1) liveNeighbors++;

        if ((liveNeighbors < 2 || liveNeighbors > 3) && board[i][j]) board[i][j] = -1;
        if (liveNeighbors == 3 && !board[i][j]) board[i][j] = 2;
      }
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == 2 || board[i][j] == 1) board[i][j] = 1;
        else board[i][j] = 0;
      }
    }
  }
};

// test
int main() {
  Solution solution;

  vector<vector<int>> board = {
    {1,1},
    {1,0}
  };
  solution.gameOfLife(board);
  for (auto row : board) {
    for (auto i : row) cout << i << " ";
    cout << endl;
  }

  return 0;
}


