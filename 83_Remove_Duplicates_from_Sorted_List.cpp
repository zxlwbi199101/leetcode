/*
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * Given a sorted linked list, delete all duplicates such that each element
 * appear only once.
 *
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// solution 1
class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (!head) return head;

    ListNode* h = head;
    ListNode* cur = head;
    int v = head->val;

    while (cur) {
      if (v != cur->val) {
        h->next = cur;
        v = cur->val;
        h = cur;
      }
      cur = cur->next;
    }
    h->next = cur;

    return head;
  }
};


// test
int main() {
  // Solution solution;
  // ListNode node = {1};
  // ListNode node2 = {2};
  // ListNode node3 = {3};
  // ListNode node4 = {4};

  // node.next = &node2;
  // node2.next = &node3;
  // node3.next = &node4;

  // ListNode* ite = solution.reverseList(&node);

  // while (ite) {
  //   cout << ite -> val << endl;
  //   ite = ite -> next;
  // }

  return 0;
}


