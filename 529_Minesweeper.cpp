/*
 * https://leetcode.com/problems/minesweeper/description/
 *
 * Let's play the minesweeper game (Wikipedia, online game)!
 *
 * You are given a 2D char matrix representing the game board. 'M' represents an
 * unrevealed mine, 'E' represents an unrevealed empty square, 'B' represents a
 * revealed blank square that has no adjacent (above, below, left, right, and all
 * 4 diagonals) mines, digit ('1' to '8') represents how many mines are adjacent
 * to this revealed square, and finally 'X' represents a revealed mine.
 *
 * Now given the next click position (row and column indices) among all the
 * unrevealed squares ('M' or 'E'), return the board after revealing this
 * position according to the following rules:
 *
 * If a mine ('M') is revealed, then the game is over - change it to 'X'.
 * If an empty square ('E') with no adjacent mines is revealed, then change it
 * to revealed blank ('B') and all of its adjacent unrevealed squares should
 * be revealed recursively.
 * If an empty square ('E') with at least one adjacent mine is revealed, then
 * change it to a digit ('1' to '8') representing the number of adjacent mines.
 * Return the board when no more squares will be revealed.
 * ......
 *
 */

#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

// solution 1
class Solution {
public:
  vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    // if click the mine
    // GAME OVER
    //
    if (board[click[0]][click[1]] == 'M') {
      board[click[0]][click[1]] = 'X';
      return board;
    }

    // click the empty square
    // reveal all its adjacent
    //
    walk(board, click[0], click[1]);
    return board;
  }

  char walk(vector<vector<char>>& board, int row, int col) {
    if (board[row][col] != 'E') {
      return board[row][col];
    }

    char mines = '0';

    // check 8 direction from up&left clockwise
    if (row > 0) {
      if (col > 0 && board[row - 1][col - 1] == 'M') mines++;
      if (board[row - 1][col] == 'M') mines++;
      if (col < board[0].size() - 1 && board[row - 1][col + 1] == 'M') mines++;
    }
    if (col < board[0].size() - 1 && board[row][col + 1] == 'M') mines++;
    if (row < board.size() - 1) {
      if (col < board[0].size() - 1 && board[row + 1][col + 1] == 'M') mines++;
      if (board[row + 1][col] == 'M') mines++;
      if (col > 0 && board[row + 1][col - 1] == 'M') mines++;
    }
    if (col > 0 && board[row][col - 1] == 'M') mines++;

    // if it's should be a number
    if (mines != '0') {
      board[row][col] = mines;
      return board[row][col];
    }

    // if this is an blank block
    board[row][col] = 'B';

    if (row > 0) {
      if (col > 0) walk(board, row - 1, col - 1);
      walk(board, row - 1, col);
      if (col < board[0].size() - 1) walk(board, row - 1, col + 1);
    }
    if (col < board[0].size() - 1) walk(board, row, col + 1);
    if (row < board.size() - 1) {
      if (col < board[0].size() - 1) walk(board, row + 1, col + 1);
      walk(board, row + 1, col);
      if (col > 0) walk(board, row + 1, col - 1);
    }
    if (col > 0) walk(board, row, col - 1);

    return 'B';
  }
};


// test
int main() {
  return 0;
}


