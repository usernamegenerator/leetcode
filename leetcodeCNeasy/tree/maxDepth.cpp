// https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/7/trees/47/
/*
二叉树的最大深度
给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。
*/

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
class Solution
{
public:
    /*
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        queue<TreeNode *> q;
        q.push(root);
        int level = 0;
        while (!q.empty())
        {
            level++;
            int nextLevelSize = q.size();
            for (int i = 0; i < nextLevelSize; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                if (temp->left != NULL)
                    q.push(temp->left);
                if (temp->right != NULL)
                    q.push(temp->right);
            }
        }
        return level;
    }
*/
    // recursive
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return NULL;
        if (root->left == NULL & root->right == NULL)
        {
            return 1;
        }
        return (1 + max(maxDepth(root->left), maxDepth(root->right)));
    }
};