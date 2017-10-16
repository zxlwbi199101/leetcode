/*
 * https://leetcode.com/problems/linked-list-cycle/description/
 *
 * Given a linked list, determine if it has a cycle in it.
 *
 * Follow up:
 * Can you solve it without using extra space?
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
  bool hasCycle(ListNode *head) {
    ListNode* hare = head;
    ListNode* tortoise = head;

    while (hare && tortoise) {
      tortoise = tortoise->next;
      hare = hare->next;
      if (hare) hare = hare->next;
      else return false;

      if (hare == tortoise) return true;
    }

    return false;
  }
};


// test
int main() {
  return 0;
}


