// 206. Reverse Linked List | Nov 21, 2023

#include "ListNode.h"
#include <iostream>

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    if (!head || !head->next) {
      return head;
    }

    ListNode *prev = nullptr;
    ListNode *cur = head;
    ListNode *next = cur->next;

    while (next) {
      cur->next = prev;
      prev = cur;
      cur = next;
      next = next->next;
    }

    cur->next = prev;
    return cur;

    // if (!head) {
    //   return nullptr;
    // }
    // if (!head->next) {
    //   return head;
    // }
    // if (!head->next->next) {
    //   head->next->next = head;
    //   head->next = nullptr;
    //   return head;
    // }
    // ListNode *cur = head;
    // ListNode *next = cur->next;
    // ListNode *next_next = next->next;
    // cur->next = nullptr;
    // while (next_next->next) {
    //   next->next = cur;
    //   cur = next;
    //   next = next_next;
    //   next_next = next_next->next;
    // }
    // return next;
  }
  Solution() {}
};

int main() { Solution(); }
