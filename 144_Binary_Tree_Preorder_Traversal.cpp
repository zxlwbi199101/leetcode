/*
 * https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 *
 * Given a binary tree, return the preorder traversal of its nodes' values.
 *
 * For example:
 * Given binary tree {1,#,2,3},
 *    1
 *     \
 *      2
 *     /
 *    3
 * return [1,2,3].
 *
 * Note: Recursive solution is trivial, could you do it iteratively?
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
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    if (!root) return result;

    stack<TreeNode*> s;
    s.push(root);

    while (!s.empty()) {
      TreeNode* temp = s.top();
      s.pop();

      if (temp->right) {
        s.push(temp->right);
      }
      if (temp->left) {
        s.push(temp->left);
      }
      result.push_back(temp->val);
    }

    return result;
  }
};

// test
int main() {
  return 0;
}


