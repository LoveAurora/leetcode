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
vector<int> preorderTraversal(TreeNode *root)
{
  /*
  vector<int> nums = {};
  preorder(root, nums);
  return nums;
  */
  vector<int> res = {};
  if (root == nullptr)
    return res;
  TreeNode *node = root;
  stack<TreeNode *> stk;
  stk.push(root);
  while (!stk.empty() || node != nullptr)
  {
    while (node != nullptr)
    {
      res.emplace_back(node->val);
      stk.emplace(node);
      node = node->left;
    }
    node = stk.top();
    stk.pop();
    node = node->right;
  }
}
void preorder(TreeNode *root, vector<int> &nums)
{
  if (root == nullptr)
    return;
  nums.push_back(root->val);
  preorder(root->left, nums);
  preorder(root->right, nums);
}

int main()
{
  return 0;
}
