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
  ListNode *swapPairs(ListNode *head)
  {
    if (head == nullptr || head->next == nullptr)
      return head;
    ListNode *temp, *node1, *node2;
    // temp = head;
    // head = head->next;
    // temp->next = head->next;
    // head->next = temp;
    // node1 = head;
    // node2 = head->next;
    node1 = head;
    node2 = head->next;
    head = node2;
    int flag = 1;
    while (node1 != nullptr && node2 != nullptr)
    {
      if (flag == 1)
      {
        node1->next = node2->next;
        node2->next = node1;
        temp = node1;
        node1 = node1->next;
        node2 = node1->next;
      }
      else
      {
        node1->next = node2->next;
        node2->next = node1;
        temp->next = node2;
        temp = node1;
        node2 = node1->next->next;
        node1 = node1->next;
      }
      flag = 0;
    }
    return head;
  }
};
int main()
{
  ListNode *l;
  Solution solution;
  vector<int> v = {1, 2, 3, 4, 5};
  l = solution.arrayToLinkedList(v);
  solution.printLinkedList(l);
  l = solution.swapPairs(l);
  solution.printLinkedList(l);
}
