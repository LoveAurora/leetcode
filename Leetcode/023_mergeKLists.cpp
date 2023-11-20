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
  ListNode *mergeTwoLists(ListNode *a, ListNode *b)
  {
    if ((!a) || (!b))
      return a ? a : b;
    ListNode head, *tail = &head, *aPtr = a, *bPtr = b;
    while (aPtr && bPtr) // aPtr或bPtr有一个为空指针就退出循环
    {
      if (aPtr->val < bPtr->val)
      {
        tail->next = aPtr;
        aPtr = aPtr->next;
      }
      else
      {
        tail->next = bPtr;
        bPtr = bPtr->next;
      }
      tail = tail->next;
    }
    tail->next = (aPtr ? aPtr : bPtr);
    // 因为退出循环时百分百有一条链已经排完序了，
    // 另外一条链就不用排了，直接tail->next指向就行
    return head.next;
  }
  ListNode *mergeKLists(vector<ListNode *> &lists)
  {
    int len = lists.size();
    if (len == 0)
      return nullptr;
    while (len > 1)
    {
      if (len % 2 == 1)
      {
        int j = 0;
        for (int i = 0; i < len - 1; i = i + 2)
        {
          lists[j] = mergeTwoLists(lists[i], lists[i + 1]);
          j++;
        }
        lists[j] = lists[len - 1];
        len = len / 2 + 1;
      }
      else
      {
        int j = 0;
        for (int i = 0; i < len - 1; i = i + 2)
        {
          lists[j] = mergeTwoLists(lists[i], lists[i + 1]);
          j++;
        }
        len /= 2;
      }
    }
    return lists[0];
  }
  ListNode *mergeKLists_priority_queue(vector<ListNode *> &lists)
  {
    lists.erase(remove_if(lists.begin(), lists.end(), [](auto &p)
                          { return !p; }),
                lists.end());
    auto compareFunc = [](auto &a, auto &b)
    { return a->val > b->val; };
    priority_queue<ListNode *, vector<ListNode *>, decltype(compareFunc)> q{lists.begin(), lists.end()};
    ListNode head;
    for (auto p = &head; !q.empty(); q.pop())
    {
      p->next = q.top();
      p = p->next;
      if (p->next != nullptr)
        q.push(p->next);
    }
    return head.next;
  }
};
int main()
{
}
