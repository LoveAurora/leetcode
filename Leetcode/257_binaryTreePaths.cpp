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

vector<string> binaryTreePaths(TreeNode *root)
{

  vector<string> str;
  queue<TreeNode *> q1;
  queue<string> q2;
  TreeNode *node;
  string s;
  if (!root)
    return str;
  q1.push(root);
  q2.push(to_string(root->val));
  while (!q1.empty())
  {
    node = q1.front();
    q1.pop();
    s = q2.front();
    q2.pop();
    if (node->left != nullptr)
    {
      q1.push(node->left);
      q2.push(s + "->" + to_string(node->left->val));
    }
    if (node->right != nullptr)
    {
      q1.push(node->right);
      q2.push(s + "->" + to_string(node->right->val));
    }
    if (!node->left && !node->right)
    {
      str.push_back(s);
    }
  }
  return str;
}
void preorder(TreeNode *root, vector<string> v)
{
  if (root == nullptr)
    return;
}

int main()
{
}