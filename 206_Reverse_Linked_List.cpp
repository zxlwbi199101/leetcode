/*
 * https://leetcode.com/problems/reverse-linked-list/#/description
 *
 * Reverse a singly linked list.
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
  ListNode* reverseList(ListNode* head) {
    if (!head || !head -> next) return head;

    ListNode* next = head -> next;
    ListNode* last = NULL;

    while (head) {
      next = head -> next;
      head -> next = last;
      last = head;

      head = next;
    }

    return last;
  }
};


// test
int main() {
  Solution solution;
  ListNode node = {1};
  ListNode node2 = {2};
  ListNode node3 = {3};
  ListNode node4 = {4};

  node.next = &node2;
  node2.next = &node3;
  node3.next = &node4;

  ListNode* ite = solution.reverseList(&node);

  while (ite) {
    cout << ite -> val << endl;
    ite = ite -> next;
  }

  return 0;
}


