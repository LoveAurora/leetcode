#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
  ListNode *arrayToLinkedList(const vector<int> &nums)
  {
    ListNode *dummy = new ListNode(0);
    ListNode *current = dummy;

    for (int num : nums)
    {
      current->next = new ListNode(num);
      current = current->next;
    }

    return dummy->next;
  }
  // 打印链表
  void printLinkedList(ListNode *head)
  {
    while (head != nullptr)
    {
      cout << head->val << " ";
      head = head->next;
    }
    cout << endl;
  }
  ListNode *mergeKLists(vector<ListNode *> &lists)
  {
  }
};
int main()
{
}
