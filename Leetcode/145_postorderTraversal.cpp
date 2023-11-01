#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr){};
  TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){};
};

vector<int> postorderTraversal(TreeNode *root)
{
  vector<int> res;
  if (root == nullptr)
  {
    return res;
  }
  stack<TreeNode *> stk1, stk2;
  stk1.push(root);
  while (!stk1.empty())
  {
    TreeNode *node = stk1.top();
    stk2.push(node);
    stk1.pop();
    if (node->left)
    {
      stk1.push(node->left);
    }
    if (node->right)
    {
      stk1.push(node->right);
    }
  }
  while (!stk2.empty())
  {
    res.push_back(stk2.top()->val);
    stk2.pop();
  }

  return res;
}

void postorder(TreeNode *root, vector<int> &res)
{
  if (root == nullptr)
    return;
  postorder(root->left, res);
  postorder(root->right, res);
  res.push_back(root->val);
}
