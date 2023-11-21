// 21. Merge Two Sorted Lists | Nov 19, 2023

#include "ListNode.h"
#include <iostream>

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *head = new ListNode();
    ListNode *cur = head;
    while (list1 && list2) {
      if (list1->val < list2->val) {
        cur->next = list1;
        list1 = list1->next;
      } else {
        cur->next = list2;
        list2 = list2->next;
      }
      cur = cur->next;
    }
    if (list1) {
      cur->next = list1;
    }
    if (list2) {
      cur->next = list2;
    }
    return head->next;
  }
  Solution() {}
};

int main() { Solution(); }
