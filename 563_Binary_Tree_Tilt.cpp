/*
 * https://leetcode.com/problems/binary-tree-tilt/#/description
 *
 * Given a binary tree, find its maximum depth.
 * The maximum depth is the number of nodes along the longest path from
 * the root node down to the farthest leaf node.
 *
 */

#include <iostream>
#include <string>
#include <stack>
#include <set>
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
  int findTilt(TreeNode* root) {
    if (!root) return 0;

    stack<TreeNode*> stk;
    TreeNode* temp = NULL;
    TreeNode* last = NULL;
    int sum = 0;

    while (!stk.empty() || root) {
      if (root) {
        stk.push(root);
        root = root -> left;
      } else {
        temp = stk.top();

        if (temp -> right && temp -> right != last) {
          root = temp -> right;
        } else {
          int left = temp -> left ? temp -> left -> val : 0;
          int right = temp -> right ? temp -> right -> val : 0;

          sum += abs(left - right);
          temp -> val += left + right;

          last = temp;
          stk.pop();
        }
      }
    }

    return sum;
  }
};


// test
int main() {
  Solution solution;

  TreeNode l_3 = {1};
  TreeNode l_2 = {2};
  TreeNode l_1 = {3};
  TreeNode root = {4};
  root.left = &l_1;
  root.right = &l_2;
  l_1.left = &l_3;

  cout << solution.findTilt(&root) << endl;

  return 0;
}


