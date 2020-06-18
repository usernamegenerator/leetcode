/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (45.83%)
 * Likes:    1816
 * Dislikes: 98
 * Total Accepted:    338.5K
 * Total Submissions: 730.2K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values. (ie, from left to right, then right to left for the next level and
 * alternate between).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its zigzag level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
 * ⁠ [15,7]
 * ]
 * 
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        queue<TreeNode *> q;
        q.push(root);
        int thisLevelCnt = 1;
        int nextLevelCnt = 0;
        bool isThisLevelOdd = true;
        while (!q.empty())
        {
            vector<int> thisLevelVector;
            stack<int> thisLevelStk;
            
            for (int i = 0; i < thisLevelCnt; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                if (isThisLevelOdd)
                {
                    thisLevelVector.push_back(temp->val);
                }
                else
                {
                    thisLevelStk.push(temp->val);
                }
                if (temp->left)
                {
                    q.push(temp->left);
                    nextLevelCnt++;
                }
                if (temp->right)
                {
                    q.push(temp->right);
                    nextLevelCnt++;
                }
            }
            if (!isThisLevelOdd)
            {
                while (!thisLevelStk.empty())
                {
                    thisLevelVector.push_back(thisLevelStk.top());
                    thisLevelStk.pop();
                }
            }
            res.push_back(thisLevelVector);
            thisLevelCnt = nextLevelCnt;
            nextLevelCnt = 0;
            isThisLevelOdd = !isThisLevelOdd;
        }
        return res;
    }
};
// @lc code=end
