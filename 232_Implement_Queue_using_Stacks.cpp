/*
 * https://leetcode.com/problems/implement-queue-using-stacks/description/
 *
 * Implement the following operations of a queue using stacks.
 *
 * push(x) -- Push element x to the back of queue.
 * pop() -- Removes the element from in front of queue.
 * peek() -- Get the front element.
 * empty() -- Return whether the queue is empty.
 * Notes:
 * You must use only standard operations of a stack -- which means only push to
 * top, peek/pop from top, size, and is empty operations are valid.
 * Depending on your language, stack may not be supported natively. You may
 * simulate a stack by using a list or deque (double-ended queue), as long as
 * you use only standard operations of a stack.
 * You may assume that all operations are valid (for example, no pop or peek
 * operations will be called on an empty queue).
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <math.h>
#include <ctype.h>
using namespace std;

// solution 1
class MyQueue {
public:
  stack<int> s, out;
  /** Initialize your data structure here. */
  MyQueue() {

  }

  /** Push element x to the back of queue. */
  void push(int x) {
    s.push(x);
  }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    if (empty()) return -1;
    int front = peek();
    out.pop();
    return front;
  }

  /** Get the front element. */
  int peek() {
    if (out.empty()) {
      if (s.empty()) return -1;

      while (!s.empty()) {
        out.push(s.top());
        s.pop();
      }
    }

    return out.top();
  }

  /** Returns whether the queue is empty. */
  bool empty() {
    return out.empty() && s.empty();
  }
};

// test
int main() {
  MyQueue obj = new MyQueue();
  obj.push(x);
  int param_2 = obj.pop();
  int param_3 = obj.peek();
  bool param_4 = obj.empty();

  return 0;
}



