/*
 * https://leetcode.com/problems/print-binary-tree/description/
 *
 * Print a binary tree in an m*n 2D string array following these rules:
 *
 * The row number m should be equal to the height of the given binary tree.
 * The column number n should always be an odd number.
 * The root node's value (in string format) should be put in the exactly middle
 * of the first row it can be put. The column and the row where the root node
 * belongs will separate the rest space into two parts (left-bottom part and
 * right-bottom part). You should print the left subtree in the left-bottom part
 *  and print the right subtree in the right-bottom part. The left-bottom part
 * and the right-bottom part should have the same size. Even if one subtree is
 * none while the other is not, you don't need to print anything for the none
 * subtree but still need to leave the space as large as that for the other
 * subtree. However, if two subtrees are none, then you don't need to leave
 * space for both of them.
 * Each unused space should contain an empty string "".
 * Print the subtrees following the same rules.
 * Example 1:
 * Input:
 *      1
 *     /
 *    2
 * Output:
 * [["", "1", ""],
 *  ["2", "", ""]]
 * Example 2:
 * Input:
 *      1
 *     / \
 *    2   3
 *     \
 *      4
 * Output:
 * [["", "", "", "1", "", "", ""],
 *  ["", "2", "", "", "", "3", ""],
 *  ["", "", "4", "", "", "", ""]]
 * Example 3:
 * Input:
 *       1
 *      / \
 *     2   5
 *    /
 *   3
 *  /
 * 4
 * Output:
 *
 * [["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
 *  ["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
 *  ["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
 *  ["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]
 * Note: The height of binary tree is in the range of [1, 10].
 *
 */

#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <list>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// solution 1
class Solution {
public:
  int maxCol = 0;
  vector<vector<string>> result;

  vector<vector<string>> printTree(TreeNode* root) {
    // get max height
    int maxDepth = 0;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
      int len = q.size();
      maxDepth++;

      for (int i = 0; i < len; i++) {
        if (q.front()->left) q.push(q.front()->left);
        if (q.front()->right) q.push(q.front()->right);
        q.pop();
      }
    }
    maxCol = (1 << maxDepth) - 1;

    // initiate the string matrix
    result = vector<vector<string>>(maxDepth,
                                    vector<string>(maxCol, "")
                                    );

    walk(root, 1, 0);
    return result;
  }

  void walk(TreeNode* root, int depth, int idx) {
    int chunk = maxCol / (1 << depth) + 1;
    int index = 2 * idx * chunk + chunk - 1;

    result[depth - 1][index] = to_string(root->val);

    if (root->left) walk(root->left, depth + 1, idx * 2);
    if (root->right) walk(root->right, depth + 1, idx * 2 + 1);
  }
};


// test
int main() {
  TreeNode* root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->right = new TreeNode(3);

  Solution s;
  s.printTree(root);
  return 0;
}


