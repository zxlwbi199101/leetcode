/*
 * https://leetcode.com/problems/construct-string-from-binary-tree/#/description
 *
 * You need to construct a string consists of parenthesis and integers from a
 * binary tree with the preorder traversing way.
 *
 * The null node needs to be represented by empty parenthesis pair "()". And you
 * need to omit all the empty parenthesis pairs that don't affect the one-to-one
 * mapping relationship between the string and the original binary tree.
 *
 */

#include <iostream>
#include <sstream>
#include <string>
#include <set>
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
  string tree2str(TreeNode* t) {
    if (!t) return "";

    stack<TreeNode*> stk;
    set<TreeNode*> visited;
    string result;

    stk.push(t);

    while (!stk.empty()) {
      t = stk.top();

      if (visited.find(t) != visited.end()) {
        stk.pop();
        result += ")";
      } else {
        result += "(" + to_string(t -> val);
        visited.insert(t);

        if (!t -> left && t -> right) result += "()";

        if (t -> right) stk.push(t -> right);
        if (t -> left) stk.push(t -> left);
      }
    }

    return result.substr(1, result.size() - 2);
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

  cout << solution.tree2str(&root) << endl;

  return 0;
}


