/*
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * ou are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 *
 */

#include <iostream>
#include <string>
#include <stack>
#include <set>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    bool carry = false;
    ListNode* result = new ListNode(0);
    ListNode* temp = result;

    while (l1 || l2) {
      int sum = carry;
      if (l1) sum += l1->val;
      if (l2) sum += l2->val;

      if (sum >= 10) {
        sum -= 10;
        carry = true;
      } else {
        carry = false;
      }

      result->next = new ListNode(sum);
      result = result->next;

      if (l1) l1 = l1->next;
      if (l2) l2 = l2->next;
    }

    if (carry) result->next = new ListNode(1);
    return temp->next ? temp->next : temp;
  }
};

// test
int main() {
  Solution solution;

  // TreeNode l_3 = {1};
  // TreeNode l_2 = {2};
  // TreeNode l_1 = {3};
  // TreeNode root = {4};
  // root.left = &l_1;
  // root.right = &l_2;
  // l_1.left = &l_3;

  // cout << solution.findTilt(&root) << endl;

  return 0;
}


