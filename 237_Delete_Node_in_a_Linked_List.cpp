/*
 * https://leetcode.com/problems/delete-node-in-a-linked-list/#/solutions
 *
 * Write a function to delete a node (except the tail) in a singly linked list,
 * given only access to that node.
 *
 * Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node
 * with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
 *
 */

#include <iostream>
#include <string>
#include <map>
#include <vector>
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
  void deleteNode(ListNode* node) {
    while (true) {
      node -> val = node -> next -> val;

      if (!node -> next -> next) {
        node -> next = NULL;
        break;
      }
      node  = node -> next;
    }
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

  solution.deleteNode(&node);

  ListNode* ite = &node;

  while (ite) {
    cout << ite -> val << endl;
    ite = ite -> next;
  }

  return 0;
}


