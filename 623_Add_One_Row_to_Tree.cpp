/*
 * https://leetcode.com/problems/add-one-row-to-tree/description/
 *
 * Given the root of a binary tree, then value v and depth d, you need to add
 * a row of nodes with value v at the given depth d. The root node is at depth 1.
 *
 * The adding rule is: given a positive integer depth d, for each NOT null tree
 * nodes N in depth d-1, create two tree nodes with value v as N's left subtree
 * root and right subtree root. And N's original left subtree should be the left
 * subtree of the new left subtree root, its original right subtree should be the
 * right subtree of the new right subtree root. If depth d is 1 that means there
 * is no depth d-1 at all, then create a tree node with value v as the new root
 * of the whole original tree, and the original tree is the new root's left subtree.
 *
 * Example 1:
 * Input:
 * A binary tree as following:
 *        4
 *      /   \
 *     2     6
 *    / \   /
 *   3   1 5
 *
 * v = 1
 *
 * d = 2
 *
 * Output:
 *        4
 *       / \
 *      1   1
 *     /     \
 *    2       6
 *   / \     /
 *  3   1   5
 *
 * Example 2:
 * Input:
 * A binary tree as following:
 *       4
 *      /
 *     2
 *    / \
 *   3   1
 *
 * v = 1
 *
 * d = 3
 *
 * Output:
 *       4
 *      /
 *     2
 *    / \
 *   1   1
 *  /     \
 * 3       1
 * Note:
 * The given d is in range [1, maximum depth of the given tree + 1].
 * The given binary tree has at least one tree node.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <math.h>
#include <ctype.h>
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
  TreeNode* addOneRow(TreeNode* root, int v, int d) {
    queue<TreeNode*> q;
    TreeNode* temp = NULL;
    q.push(root);

    if (d == 1) {
      temp = new TreeNode(v);
      temp->left = root;
      return temp;
    }

    for (int i = 0; i < d - 2; i++) {
      for (int j = q.size(); j > 0; j--) {
        if (q.front()->left) q.push(q.front()->left);
        if (q.front()->right) q.push(q.front()->right);
        q.pop();
      }
    }

    while (!q.empty()) {
      temp = new TreeNode(v);
      if (q.front()->left) {
        temp->left = q.front()->left;
      }
      q.front()->left = temp;

      temp = new TreeNode(v);
      if (q.front()->right) {
        temp->right = q.front()->right;
      }
      q.front()->right = temp;

      q.pop();
    }

    return root;
  }
};

// test
int main() {
  return 0;
}



