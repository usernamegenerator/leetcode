// https://leetcode-cn.com/explore/featured/card/top-interview-questions-easy/7/trees/49/
/*
对称二叉树
给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3
说明:

如果你可以运用递归和迭代两种方法解决这个问题，会很加分。
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    /*
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int qSize = q.size();
            vector<int> level;
            for (int i = 0; i < qSize; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                // if a position is empty
                // fill dummy value to the empty slot
                // make sure the level is full for isVectorSymmetric
                if (temp == NULL)
                {
                    level.push_back(INT_MIN);
                    continue;
                }
                level.push_back(temp->val);
                if (temp->left != NULL)
                    q.push(temp->left);
                else
                {
                    q.push(NULL);
                }
                if (temp->right != NULL)
                    q.push(temp->right);
                else
                {
                    q.push(NULL);
                }
            }
            if (!isVectorSymmetric(level))
            {
                return false;
            }
        }
        return true;
    }
    bool isVectorSymmetric(vector<int> &res)
    {
        for (int i = 0, j = res.size() - 1; i < j; i++, j--)
        {
            if (res[i] != res[j])
                return false;
        }
        return true;
    }
    */

    // recursive method
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;
        return symmetric(root->left, root->right);
    }
    bool symmetric(TreeNode *left, TreeNode *right)
    {
        if (left == NULL && right == NULL)
            return true;
        if (left == NULL && right != NULL)
            return false;
        if (left != NULL && right == NULL)
            return false;
        // both non-null
        if ((left->val != right->val))
            return false;
        else
            return (symmetric(left->left, right->right) && symmetric(left->right, right->left));
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(3);
    Solution s;
    cout << s.isSymmetric(root) << endl;
}