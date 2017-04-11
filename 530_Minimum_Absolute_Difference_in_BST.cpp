/*
 * https://leetcode.com/problems/minimum-absolute-difference-in-bst/#/description
 *
 * Given a binary search tree with non-negative values, find the minimum
 * absolute difference between values of any two nodes.
 *
 */

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <stdlib.h>
#include <climits>
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
  int getMinimumDifference(TreeNode* root) {
    if (!root) return 0;

    stack<TreeNode*> stk;
    TreeNode* temp = root;

    TreeNode* lastValueNode = NULL;
    int minValue = INT_MAX;

    while (temp) {
      stk.push(temp);
      temp = temp -> left;
    }

    while (!stk.empty()) {
      temp = stk.top();
      stk.pop();

      if (lastValueNode) {
        minValue = min(minValue, abs(lastValueNode -> val - temp -> val));

        if (!minValue) return 0;
      }
      lastValueNode = temp;

      if (temp -> right) {
        temp = temp -> right;

        while (temp) {
          stk.push(temp);
          temp = temp -> left;
        }
      }
    }

    return minValue;
  }
};


// test
int main() {
  Solution solution;

  TreeNode l_3 = {3};
  TreeNode l_2 = {2};
  TreeNode l_1 = {1};
  TreeNode root = {0};
  root.left = &l_1;
  l_1.left = &l_2;
  l_2.left = &l_3;

  cout << solution.getMinimumDifference(&root) << endl;

  return 0;
}


