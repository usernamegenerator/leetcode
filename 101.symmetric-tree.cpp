/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (44.54%)
 * Likes:    2857
 * Dislikes: 66
 * Total Accepted:    495.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
 * 
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 
 * 
 * But the following [1,2,2,null,3,null,3] is not:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 
 * 
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
 * 
 */

// @lc code=start
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
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int numElementInThisLevel = q.size();
            vector<int> thisLevel;
            for (int i = 0; i < numElementInThisLevel; i++)
            {
                TreeNode *temp = q.front();
                if (temp == NULL)
                {
                    thisLevel.push_back(INT_MIN);
                }
                else
                {
                    thisLevel.push_back(temp->val);
                    q.push(temp->left);
                    q.push(temp->right);
                }
                q.pop();
            }
            for (int i = 0, j = numElementInThisLevel - 1; i < j; i++, j--)
            {
                if (thisLevel[i] != thisLevel[j])
                {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
