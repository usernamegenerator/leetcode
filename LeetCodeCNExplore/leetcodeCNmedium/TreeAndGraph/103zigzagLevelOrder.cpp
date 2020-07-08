/*
二叉树的锯齿形层次遍历
给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层次遍历如下：

[
  [3],
  [20,9],
  [15,7]
]
*/

#include <queue>
#include <stack>
#include <vector>
#include <iostream>

using namespace std;

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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        queue<TreeNode *> levelQueue;
        levelQueue.push(root);
        int level = 1; // odd from left to right, even from right to left
        int levelCount = 1;
        int nextLevelCount = 0;
        vector<int> thisLevelvector;
        stack<int> thisLevelstack; // for even only;
        while (!levelQueue.empty())
        {
            /*
            cout << "===========" << endl;
            cout << levelCount << endl;
            cout << level << endl;
            */
            TreeNode *iter = NULL;
            for (int i = 0; i < levelCount; i++)
            {
                iter = levelQueue.front();
                levelQueue.pop();
                if (level % 2) // odd, left to right
                {
                    thisLevelvector.push_back(iter->val);
                }
                else // even, right to left, use stack
                {
                    thisLevelstack.push(iter->val);
                }
                if (iter->left != NULL)
                {
                    levelQueue.push(iter->left);
                    nextLevelCount++;
                }
                if (iter->right != NULL)
                {
                    levelQueue.push(iter->right);
                    nextLevelCount++;
                }
            }

            if (level % 2 == 0) // even
            {
                while (!thisLevelstack.empty())
                {
                    thisLevelvector.push_back(thisLevelstack.top());
                    thisLevelstack.pop();
                }
            }

            levelCount = nextLevelCount;
            nextLevelCount = 0;
            level++;
            res.push_back(thisLevelvector);
            thisLevelvector.clear();
            
/*
            for(int i = 0 ; i < thisLevelvector.size();i++)
            {
                cout << thisLevelvector[i] << " ";
            }
            cout << endl;
*/
        }

        return res;
    }
};

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    Solution s;
    vector<vector<int>> res = s.zigzagLevelOrder(root);
}