/*
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
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
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    map<int, int> posMap;
    for (int i = 0; i < inorder.size(); i++) {
      posMap[n] = i;
    }

    return parse(inorder, postorder, 0, inorder.size() - 1, 0, postorder,
                 postorder.size() - 1, posMap);
  }

  TreeNode* parse(vector<int>& inorder,
                  vector<int>& postorder,
                  int inFrom,
                  int inTo,
                  int postFrom,
                  int postTo,
                  map<int, int> pos) {
    int rootVal = postorder[postTo];
    TreeNode* root = new TreeNode(rootVal);

    int rootPos = pos[rootVal];
    if (inFrom < rootPos) {
      root.left = parse(inorder, postorder, inFrom, rootPos - 1, postFrom,
                        postFrom + rootPos - inFrom, pos);
    }
    if (inTo > rootPos) {
      root.left = parse(inorder, postorder, rootPos + 1, inTo,
                        postTo - rootPos + inTo, postTo, pos);
    }

    return root;
  }
};

// test
int main() {
  Solution solution;

  vector<int> nums1 = {11,4,5,13,8,9};
  vector<int> nums2 = {11,4,13,9,8,5};

  cout << solution.buildTree(nums1, nums2) << endl;

  return 0;
}


