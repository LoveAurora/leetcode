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
  ListNode *initializeList(const std::vector<int> &values)
  {
    ListNode *dummyHead = new ListNode(); // 创建一个虚拟头节点
    ListNode *current = dummyHead;

    for (int value : values)
    {
      current->next = new ListNode(value);
      current = current->next;
    }

    return dummyHead->next; // 返回虚拟头节点的下一个节点作为结果链表的头
  }
  void printList(ListNode *head)
  {
    while (head != nullptr)
    {
      cout << head->val << " -> ";
      head = head->next;
    }
    cout << "nullptr" << endl;
  }
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    int carry = 0, sum = 0;
    ListNode *dummy = new ListNode(), *dummy1 = new ListNode(), *dummy2 = new ListNode();
    ListNode *head = l1;
    dummy1->next = l1;
    dummy2->next = l2;
    while (l1 != nullptr || l2 != nullptr)
    {
      while (l1 != nullptr && l2 != nullptr)
      {
        sum = carry + l1->val + l2->val;
        carry = sum / 10;
        l1->val = sum % 10;

        l1 = l1->next;
        l2 = l2->next;

        dummy1 = dummy1->next;
        dummy2 = dummy2->next;
      }
      while (l1 != nullptr)
      {
        sum = carry + l1->val;
        l1->val = sum % 10;
        carry = sum / 10;

        l1 = l1->next;
        dummy1 = dummy1->next;
      }
      if (l2 != nullptr)
      {
        dummy1->next = l2;
        while (l2 != nullptr)
        {
          sum = carry + l1->val;
          l1->val = sum % 10;
          carry = sum / 10;

          l2 = l2->next;
          dummy2 = dummy2->next;
        }
      }
    }
    if (carry != 0)
    {
      ListNode *node = new ListNode(carry);
      if (dummy1 == nullptr)
        dummy1 = dummy1->next;
      else
        dummy2 = dummy2->next;
    }
    return head;
  }
};

int main()
{
  Solution sol;
  vector<int> value1 = {2, 4, 3};
  vector<int> value2 = {5, 6, 4};

  ListNode *myList1 = sol.initializeList(value1);
  ListNode *myList2 = sol.initializeList(value2);
  // 使用 printList 函数打印链表
  sol.printList(myList1);
  sol.printList(myList2);
  sol.addTwoNumbers(myList1, myList2);
  // 记得释放链表的内存
  while (myList1 != nullptr)
  {
    ListNode *temp = myList1;
    myList1 = myList1->next;
    delete temp;
  }
  while (myList2 != nullptr)
  {
    ListNode *temp = myList2;
    myList2 = myList2->next;
    delete temp;
  }

  return 0;
}