// 876. Middle of the Linked List | Nov 22, 2023

#include <iostream>
#include "ListNode.h"

class Solution {
public:
  ListNode *middleNode(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }
  Solution() {}
};

int main() { Solution(); }
