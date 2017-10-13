/*
 * https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
 *
 * Given a Binary Search Tree and a target number, return true if there exist
 * two elements in the BST such that their sum is equal to the given target.
 *
 * Example 1:
 * Input:
 *     5
 *    / \
 *   3   6
 *  / \   \
 * 2   4   7
 *
 * Target = 9
 *
 * Output: True
 * Example 2:
 * Input:
 *     5
 *    / \
 *   3   6
 *  / \   \
 * 2   4   7
 *
 * Target = 28
 *
 * Output: False
 *
 */

#include <iostream>
#include <string>
#include <stack>
#include <set>
#include <unordered_set>
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
  // bool findTarget(TreeNode* root, int k) {
  //   unordered_set<int> s;
  //   stack<TreeNode*> stk;
  //   stk.push(root);

  //   while (!stk.empty()) {
  //     root = stk.top();
  //     stk.pop();
  //     if (root->left) stk.push(root->left);
  //     if (root->right) stk.push(root->right);

  //     s.insert(root->val);
  //   }

  //   for (auto it = s.begin(); it != s.end(); it++) {
  //     int i = k - *it;
  //     if (i * 2 != k && s.find(i) != s.end()) return true;
  //   }
  //   return false;
  // }

  bool findTarget(TreeNode* root, int k) {
    stack<TreeNode*> stk;
    stk.push(root);

    while (!stk.empty()) {
      TreeNode* temp = stk.top();
      if (2 * temp->val != k && search(root, k - temp->val)) return true;

      stk.pop();
      if (temp->left) stk.push(temp->left);
      if (temp->right) stk.push(temp->right);
    }

    return false;
  }

  bool search(TreeNode* root, int t) {
    if (t < root->val && root->left) return search(root->left, t);
    if (t > root->val && root->right) return search(root->right, t);
    if (t == root->val) return true;
    return false;
  }
};


// test
int main() {
  Solution solution;

  // TreeNode l_1 = {3};
  // TreeNode l_2 = {0};
  // TreeNode l_3 = {4};
  // TreeNode l_4 = {2};
  // TreeNode l_5 = {4};
  // TreeNode l_6 = {1};

  // l_2.left = &l_4;
  // l_2.right = &l_5;
  // l_3.right = &l_6;
  // l_1.left = &l_2;
  // l_1.right = &l_3;

  // cout << solution.longestUnivaluePath(&l_1) << endl;

  return 0;
}


