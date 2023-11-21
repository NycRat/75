// 141. Linked List Cycle | Nov 21, 2023

#include "ListNode.h"
#include <iostream>

class Solution {
public:
  bool hasCycle(ListNode *head) {
    if (!head) {
      return false;
    }
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (slow && fast && fast->next) {
      if (slow == fast) {
        return true;
      }
      slow = slow->next;
      fast = fast->next->next;
    }
    return false;
  }
  Solution() {}
};

int main() { Solution(); }
