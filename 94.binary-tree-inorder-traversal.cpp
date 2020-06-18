/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (61.53%)
 * Likes:    2846
 * Dislikes: 122
 * Total Accepted:    697.8K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [1,3,2]
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        if (root == NULL)
        {
            return res;
        }
        stack<TreeNode *> stk;

        TreeNode *cur = root;
        while (cur || !stk.empty())
        {
            if (cur)
            {
                stk.push(cur);
                cur = cur->left;
            }
            else
            {
                TreeNode *temp = stk.top();
                stk.pop();
                res.push_back(temp->val);
                cur = temp->right;
            }
        }
        return res;
    }
    /*
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> v;
        inorderRecursive(root, v);
        return v;
    }
    void inorderRecursive(TreeNode *root, vector<int> &v)
    {
        if (root == NULL)
            return;
        inorderRecursive(root->left, v);
        v.push_back(root->val);
        inorderRecursive(root->right, v);
    }
*/
};
// @lc code=end
