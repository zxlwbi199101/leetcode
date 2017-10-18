/*
 * https://leetcode.com/problems/find-bottom-left-tree-value/description/
 *
 * Given a binary tree, find the leftmost value in the last row of the tree.
 *
 * Example 1:
 * Input:
 *
 *     2
 *    / \
 *   1   3
 *
 * Output:
 * 1
 * Example 2:
 * Input:
 *
 *         1
 *        / \
 *       2   3
 *      /   / \
 *     4   5   6
 *        /
 *       7
 *
 * Output:
 * 7
 * Note: You may assume the tree (i.e., the given root node) is not NULL.
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
  int findBottomLeftValue(TreeNode* root) {
    queue<TreeNode*> q1;
    queue<TreeNode*> q2;
    q1.push(root);
    int result = root->val;

    while (!q1.empty() || !q2.empty()) {
      if (q1.empty()) {
        while (!q2.empty()) {
          if (q2.front()->left) q1.push(q2.front()->left);
          if (q2.front()->right) q1.push(q2.front()->right);
          q2.pop();
        }
        if (!q1.empty()) result = q1.front()->val;
      } else {
        while (!q1.empty()) {
          q2.push(q1.front());
          q1.pop();
        }
      }
    }

    return result;
  }
};


// test
int main() {
  return 0;
}


