/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (52.90%)
 * Likes:    1551
 * Dislikes: 159
 * Total Accepted:    315.9K
 * Total Submissions: 589.6K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given an array where elements are sorted in ascending order, convert it to a
 * height balanced BST.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 * 
 * Example:
 * 
 * 
 * Given the sorted array: [-10,-3,0,5,9],
 * 
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following
 * height balanced BST:
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if (nums.empty())
        {
            return NULL;
        }
        int mid = nums.size() / 2;
        TreeNode *root = new TreeNode(nums[mid]);

        vector<int> left;
        for (int i = 0; i < mid; i++)
        {
            left.push_back(nums[i]);
        }
        root->left = sortedArrayToBST(left);

        vector<int> right;
        for (int i = mid + 1; i < nums.size(); i++)
        {
            right.push_back(nums[i]);
        }
        root->right = sortedArrayToBST(right);

        return root;
    }
};
// @lc code=end
