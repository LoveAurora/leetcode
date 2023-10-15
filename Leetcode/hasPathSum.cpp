#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
bool hasPathSum(TreeNode *root, int targetSum)
{
  if (root == nullptr)
    return false;
  queue<TreeNode *> q1;
  queue<int> q2;
  q1.push(root);
  q2.push(root->val);
  while (!q1.empty())
  {
    TreeNode *now = q1.front();
    int temp = q2.front();
    q1.pop();
    q2.pop();
    if (now->left == nullptr && now->right == nullptr)
    {
      if (temp == targetSum)
      {
        return true;
      }
      continue;
    }
    if (now->left != nullptr)
    {
      q1.push(now->left);
      q2.push(temp + now->left->val);
    }
    if (now->right != nullptr)
    {
      q1.push(now->right);
      q2.push(temp + now->right->val);
    }
  }
  return false;
}
int main()
{
}