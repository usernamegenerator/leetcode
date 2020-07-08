/*
从前序与中序遍历序列构造二叉树
根据一棵树的前序遍历与中序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7
*/

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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (inorder.size() == 0)
            return NULL;
        int preorderPos = 0;
        int inorderLeft = 0;
        int inorderRight = inorder.size() - 1;
        return buildTreeHelper(preorder, preorderPos, inorder, inorderLeft, inorderRight);
    }

    TreeNode *buildTreeHelper(vector<int> &preorder, int &preorderPos, vector<int> &inorder, int inorderLeft, int inorderRight)
    {
        if (preorderPos >= preorder.size()) return NULL;
        TreeNode *root = new TreeNode(preorder[preorderPos]);
        int midIdx = -1;
        for (int i = inorderLeft; i <= inorderRight; i++)
        {
            if (inorder[i] == root->val)
            {
                midIdx = i;
                break;
            }
        }
        if (inorderLeft <= midIdx-1) root->left = buildTreeHelper(preorder, ++preorderPos, inorder, inorderLeft, midIdx - 1);
        if (midIdx+1 <= inorderRight) root->right = buildTreeHelper(preorder, ++preorderPos, inorder, midIdx + 1, inorderRight);
        return root;
    }
};