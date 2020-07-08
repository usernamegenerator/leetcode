// https://leetcode-cn.com/explore/featured/card/top-interview-questions-easy/7/trees/48/
/*
验证二叉搜索树
给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
示例 1:

输入:
    2
   / \
  1   3
输出: true
示例 2:

输入:
    5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    // in-order transverse, save to array
    // check if array in order
    bool isValidBST(TreeNode *root)
    {
        if (root == NULL)
            return true;
        vector<int> res;
        inorder(root, res);
        // return is_sorted(res.begin(), res.end());
        // left < root < right
        for (vector<int>::iterator it = res.begin(); it != res.end() - 1; it++)
        {
            if (*it >= *(it + 1))
            {
                return false;
            }
        }
        return true;
    }
    void inorder(TreeNode *root, vector<int> &res)
    {
        if (root == NULL)
            return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
};