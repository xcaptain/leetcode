/**
 * 问题链接：https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
 * 编译命令：clang++ two_sum_bst.cpp -std=c++14
 * 回答状态：AC
 */
#include <iostream>
#include <vector>
#include <algorithm>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution
{
  public:
    bool findTarget(TreeNode *root, int k)
    {
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
