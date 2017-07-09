/*
 * https://leetcode.com/problems/same-tree/#/description
 *
 * Given two binary trees, write a function to check if they are equal or not.
 *
 * Two binary trees are considered equal if they are structurally identical and
 * the nodes have the same value.
 *
 */

#include <iostream>
#include <string>
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
  bool isSameTree(TreeNode* p, TreeNode* q) {
    stack<pair<TreeNode*, TreeNode*>> stk;
    stk.push(make_pair(p, q));

    while (!stk.empty()) {
      pair<TreeNode*, TreeNode*> p = stk.top();
      stk.pop();

      if (!p.first && !p.second) continue;
      if ((!p.first && p.second) || (p.first && !p.second)) return false;
      if (p.first -> val != p.second -> val) return false;

      stk.push(make_pair(p.first -> left, p.second -> left));
      stk.push(make_pair(p.first -> right, p.second -> right));
    }

    return true;
  }
};


// test
int main() {
  Solution solution;

  TreeNode l_3 = {0};
  TreeNode l_2 = {0};
  TreeNode l_1 = {2};
  TreeNode root = {0};
  root.left = &l_1;
  l_1.left = &l_2;
  l_2.left = &l_3;

  TreeNode r_3 = {0};
  TreeNode r_2 = {0};
  TreeNode r_1 = {0};
  TreeNode root2 = {0};
  root2.left = &r_1;
  r_1.left = &r_2;
  r_2.left = &r_3;

  cout << solution.isSameTree(&root, &root2) << endl;

  return 0;
}


