/*
 * https://leetcode.com/problems/convert-bst-to-greater-tree/#/description
 *
 * Given a Binary Search Tree (BST), convert it to a Greater Tree such that
 * every key of the original BST is changed to the original key plus sum of
 * all keys greater than the original key in BST.
 *
 */

#include <iostream>
#include <vector>
#include <stack>
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
  TreeNode* convertBST(TreeNode* root) {
    if (!root) return root;

    stack<TreeNode*> stk;
    TreeNode* temp = root;
    int sum = 0;

    stk.push(temp);
    temp = temp -> right;

    while (!stk.empty() || temp) {
      while (temp) {
        stk.push(temp);
        temp = temp -> right;
      }
      temp = stk.top();
      stk.pop();
      sum += temp -> val;
      temp -> val = sum;

      temp = temp -> left;
    }

    return root;
  }
};

// test
int main() {
  Solution solution;

  TreeNode l3 = {5};
  TreeNode l2 = {13};
  TreeNode l1 = {2};
  TreeNode root = {5};
  root.left = &l1;
  root.right = &l2;
  // l2.right = &l3;

  TreeNode r4 = {7};
  TreeNode r3 = {4};
  TreeNode r2 = {3};
  TreeNode r1 = {1};
  TreeNode root2 = {2};
  root2.left = &r1;
  root2.right = &r2;
  r1.right = &r3;
  r2.right = &r4;

  TreeNode* result = solution.convertBST(&root);

  cout << result -> val << endl;

  return 0;
}
