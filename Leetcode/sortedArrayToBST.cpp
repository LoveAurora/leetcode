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

TreeNode *sortedArrayToBST(vector<int> &nums)
{
  return helper(nums, 0, nums.size() - 1);
  // 类似于快速排序  0到nums.size()-1 是数组的下标
  // 数组里每个数都会被访问 而如果right 是 nums.size()
  // 就会栈溢出
}
TreeNode *helper(vector<int> &nums, int left, int right)
{
  if (left > right)
    return nullptr;
  int mid = (left + right) / 2;
  TreeNode *root = new TreeNode(nums[mid]);
  root->left = helper(nums, left, mid - 1);
  root->right = helper(nums, mid + 1, right);
  return root;
}