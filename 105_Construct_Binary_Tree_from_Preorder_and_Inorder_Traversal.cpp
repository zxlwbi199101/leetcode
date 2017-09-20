/*
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
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
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (!preorder.size() || !inorder.size()) return NULL;

    int preIndex = 1;
    int inIndex = 0;
    stack<TreeNode *> s;

    TreeNode *root = new TreeNode(preorder[0]);
    TreeNode *temp = root;
    s.push(root);

    for (; preIndex < preorder.size(); preIndex++) {
      temp = s.top();

      if (temp->val != inorder[inIndex]) {
        temp->left = new TreeNode(preorder[preIndex]);
        s.push(temp->left);
      } else {
        while (!s.empty() && inorder[inIndex] == s.top()->val) {
          inIndex++;
          temp = s.top();
          s.pop();
        }

        temp->right = new TreeNode(preorder[preIndex]);
        s.push(temp->right);
      }
    }

    return root;
  }
};

// test
int main() {
  Solution solution;

  vector<int> nums1 = {1,2,4,5,8,3,6};
  vector<int> nums2 = {4,2,8,5,1,6,3};

  TreeNode* result = solution.buildTree(nums1, nums2);

  cout << result->val << endl;

  return 0;
}


