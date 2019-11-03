// https://leetcode-cn.com/explore/featured/card/top-interview-questions-easy/7/trees/51/
/*
将有序数组转换为二叉搜索树
将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

给定有序数组: [-10,-3,0,5,9],

一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5
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
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return NULL;
        }
        int low = 0;
        int high = nums.size();
        int mid = low + (high - low) / 2;
        TreeNode *root = new TreeNode(nums[mid]);

        vector<int> left;
        for (int i = low; i < mid; i++)
        {
            left.push_back(nums[i]);
        }
        if (left.size() > 0)
            root->left = sortedArrayToBST(left);

        vector<int> right;
        for (int i = mid + 1; i < high; i++)
        {
            right.push_back(nums[i]);
        }
        if (right.size() > 0)
            root->right = sortedArrayToBST(right);

        return root;
    }
};