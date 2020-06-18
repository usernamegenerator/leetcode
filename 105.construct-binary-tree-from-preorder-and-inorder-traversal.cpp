/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (46.58%)
 * Likes:    3029
 * Dislikes: 86
 * Total Accepted:    339.1K
 * Total Submissions: 716.2K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
 * 
 * Return the following binary tree:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.size() == 0 || inorder.size() == 0 || preorder.size() != inorder.size())
            return NULL;
        int preorderPos = 0;
        int inorderStart = 0;
        int inorderEnd = inorder.size() - 1;
        return buildTreeHelper(preorder, inorder, preorderPos, inorderStart, inorderEnd);
    }
    TreeNode *buildTreeHelper(vector<int> &preorder, vector<int> &inorder, int &preorderPos, int inorderStart, int intoderEnd)
    {
        if (preorderPos >= preorder.size())
            return NULL;
        TreeNode *root = new TreeNode(preorder[preorderPos]);
        int i = inorderStart;
        for (; i < intoderEnd; i++)
        {
            if (root->val == inorder[i])
            {
                break;
            }
        }
        if (inorderStart <= i - 1)
            root->left = buildTreeHelper(preorder, inorder, ++preorderPos, inorderStart, i - 1);
        if (i + 1 <= intoderEnd)
            root->right = buildTreeHelper(preorder, inorder, ++preorderPos, i + 1, intoderEnd);
        return root;
    }
};
// @lc code=end
