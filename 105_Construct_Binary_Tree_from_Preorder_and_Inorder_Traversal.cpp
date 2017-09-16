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
#include <map>
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
  // struct Meta {
  //   int preStart;
  //   int preEnd;
  //   int inStart;
  //   int inEnd;
  //   TreeNode *parent;

  //   Meta(int a, int b, int c, int d, TreeNode *e) :
  //     preStart(a), preEnd(b), inStart(c), inEnd(d), parent(e) {};
  // };

  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    map<int, int> posMap;
    for (int i = 0; i < inorder.size(); i++) {
      posMap[inorder[i]] = i;
    }

    int preIndex = 1;
    int inIndex = 0;
    TreeNode *temp = NULL;
    TreeNode *root = new TreeNode(preorder[0]);

    stack<Meta> s(root);
    while (!s.empty()) {
      temp = s.top();
      s.pop();

      inIndex = posMap[temp->val];

    }
  }
};

// test
int main() {
  Solution solution;

  vector<int> nums1 = {1,2,4,5,8,3,6,7};
  vector<int> nums2 = {4,2,8,5,1,6,3,7};

  TreeNode* result = solution.buildTree(nums1, nums2);

  cout << result->val << endl;

  return 0;
}


