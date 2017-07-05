/*
 * https://leetcode.com/problems/merge-two-binary-trees/#/description
 *
 * Given two binary trees and imagine that when you put one of them to cover the other,
 * some nodes of the two trees are overlapped while the others are not.
 *
 * You need to merge them into a new binary tree. The merge rule is that if two nodes
 * overlap, then sum node values up as the new value of the merged node.
 * Otherwise, the NOT null node will be used as the node of new tree.
 *2
 */

#include <iostream>
#include <string>
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
  TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (t1 == NULL) return t2;
    if (t2 == NULL) return t1;

    stack<TreeNode*> stk1, stk2;
    stk1.push(t1);
    stk2.push(t2);

    TreeNode* temp1 = t1;
    TreeNode* temp2 = t2;

    while (!stk1.empty()) {
      temp1 = stk1.top();
      temp2 = stk2.top();
      stk1.pop();
      stk2.pop();

      temp1 -> val += temp2 -> val;

      if (temp1 -> left != NULL && temp2 -> left != NULL) {
        stk1.push(temp1 -> left);
        stk2.push(temp2 -> left);
      } else if (temp2 -> left != NULL) {
        temp1 -> left = temp2 -> left;
      }

      if (temp1 -> right != NULL && temp2 -> right != NULL) {
        stk1.push(temp1 -> right);
        stk2.push(temp2 -> right);
      } else if (temp2 -> right != NULL) {
        temp1 -> right = temp2 -> right;
      }
    }

    return t1;
  }
};


// test
int main() {
  Solution solution;

  TreeNode l3 = {5};
  TreeNode l2 = {2};
  TreeNode l1 = {3};
  TreeNode root = {1};
  root.left = &l1;
  root.right = &l2;
  l1.left = &l3;

  TreeNode r4 = {7};
  TreeNode r3 = {4};
  TreeNode r2 = {3};
  TreeNode r1 = {1};
  TreeNode root2 = {2};
  root2.left = &r1;
  root2.right = &r2;
  r1.right = &r3;
  r2.right = &r4;

  TreeNode* result = solution.mergeTrees(&root, &root2);

  cout << result -> val << endl;
  cout << result -> left -> val << endl;
  cout << result -> right -> val << endl;
  cout << result -> left -> left -> val << endl;
  cout << result -> left -> right -> val << endl;
  cout << result -> right -> right -> val << endl;

  return 0;
}


