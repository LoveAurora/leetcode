#include <iostream>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *deleteDuplicates(ListNode *head)
{
  ListNode *m = head, *n;
  while (m->next != NULL)
  {
    n = m->next;
    if (m->val == n->val)
    {
      m->next = n->next;
      delete n;
    }
    else
    {
      m = n;
    }
  }
}
int main()
{
}