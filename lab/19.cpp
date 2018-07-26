#include "header.hpp"
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* headPointer = head;
    ListNode* tailPointer = head;
    for (int i = 0; i < n; i++) {
      tailPointer = tailPointer->next;
    }
    if (tailPointer != NULL) {
      while (tailPointer->next != NULL) {
        tailPointer = tailPointer->next;
        if (headPointer != NULL) {
          headPointer = headPointer->next;
        }
      }
    } else{
        return head->next;
    }
    if (headPointer != NULL && headPointer->next != NULL) {
      headPointer->next = headPointer->next->next;
      return head;
    } else {
      return NULL;
    }
  }
};