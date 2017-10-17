/*
 * https://leetcode.com/problems/intersection-of-two-linked-lists/description/
 *
 * Write a program to find the node at which the intersection of two singly
 * linked lists begins.
 *
 *
 * For example, the following two linked lists:
 *
 * A:          a1 → a2
 *                    ↘
 *                      c1 → c2 → c3
 *                    ↗
 * B:     b1 → b2 → b3
 * begin to intersect at node c1.
 *
 *
 * Notes:
 *
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function
 * returns.
 * You may assume there are no cycles anywhere in the entire linked structure.
 * Your code should preferably run in O(n) time and use only O(1) memory.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA || !headB) return NULL;

    int lenA = 0, lenB = 0;
    ListNode* hA = headA;
    ListNode* hB = headB;

    while (hA) {
      lenA++;
      hA = hA->next;
    }
    while (hB) {
      lenB++;
      hB = hB->next;
    }

    hA = headA;
    hB = headB;

    if (lenA > lenB) {
      while (lenA != lenB) {
        lenA--;
        hA = hA->next;
      }
    } else if (lenA < lenB) {
      while (lenA != lenB) {
        lenB--;
        hB = hB->next;
      }
    }

    while (hA) {
      if (hA == hB) return hB;
      hA = hA->next;
      hB = hB->next;
    }

    return NULL;
  }
};


// test
int main() {
  Solution solution;
  return 0;
}


