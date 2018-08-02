#include "header.hpp"
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x, ListNode* n) : val(x), next(n) {}
};

class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    ListNode fakeHead(0, NULL);
    if (!(head != NULL && head->next != NULL)) {
      return head;
    } else {
      cout << "ha" << endl;
      fakeHead.next = head->next;
    }

    ListNode *one, *two;
    for (one = head, two = head->next; one != NULL && two != NULL;) {
      cout << "one:" << one->val << " two:" << two->val << "\n";
      ListNode *nextOne, *nextTwo;
      if (two->next != NULL) {
        if (two->next->next != NULL) {
          // prepare for the next iteration
          nextOne = two->next;
          nextTwo = two->next->next;

          // swap
          two->next = one;
          one->next = nextTwo;

          // next iteration
          one = nextOne;
          two = nextTwo;
        } else {
          // prepare for the next iteration
          nextOne = two->next;

          // swap
          two->next = one;
          one->next = nextOne;
          break;
        }
      } else {
        cout << "before: two->next=NULL: one:" << one->val
             << " two:" << two->val << endl;

        // swap
        two->next = one;
        one->next = NULL;
        cout << "two->next=NULL: one:" << one->val << " two:" << two->val
             << endl;

        break;
      }
    }
    return fakeHead.next;
  }
};

int main() {
  ListNode f(6, NULL);
  ListNode e(5, &f);
  ListNode d(4, &e);
  ListNode c(3, &d);
  ListNode b(2, &c);
  ListNode a(1, &b);

  // ListNode c(3, NULL);
  // ListNode b(2, &c);
  // ListNode a(1, &b);
  for (ListNode* ln = Solution().swapPairs(&a); ln != NULL; ln = ln->next) {
    cout << ln->val << " ";
  }
}