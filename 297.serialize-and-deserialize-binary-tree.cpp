/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 *
 * https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
 *
 * algorithms
 * Hard (45.76%)
 * Likes:    2846
 * Dislikes: 138
 * Total Accepted:    313K
 * Total Submissions: 670.8K
 * Testcase Example:  '[1,2,3,null,null,4,5]'
 *
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in
 * the same or another computer environment.
 * 
 * Design an algorithm to serialize and deserialize a binary tree. There is no
 * restriction on how your serialization/deserialization algorithm should work.
 * You just need to ensure that a binary tree can be serialized to a string and
 * this string can be deserialized to the original tree structure.
 * 
 * Example: 
 * 
 * 
 * You may serialize the following tree:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * ⁠    / \
 * ⁠   4   5
 * 
 * as "[1,2,3,null,null,4,5]"
 * 
 * 
 * Clarification: The above format is the same as how LeetCode serializes a
 * binary tree. You do not necessarily need to follow this format, so please be
 * creative and come up with different approaches yourself.
 * 
 * Note: Do not use class member/global/static variables to store states. Your
 * serialize and deserialize algorithms should be stateless.
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
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == NULL)
            return "";
        string res = "";
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                res.append("null,");
            }
            else
            {
                res.append(to_string(temp->val));
                res.append(",");
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        //cout << res << endl; // // 1,2,3,null,null,4,5,null,null,null,null,
        
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.empty())
            return NULL;
        vector<string> serial;
        string temp;
        stringstream input(data);
        while (getline(input, temp, ','))
        {
            serial.push_back(temp);
        }

        queue<TreeNode *> q;
        TreeNode *root = new TreeNode(stoi(serial[0]));
        q.push(root);
        int i = 1;
        while (i < serial.size())
        {
            TreeNode *currentRoot = q.front();
            q.pop();
            if (serial[i] != "null")
            {
                TreeNode *l = new TreeNode(stoi(serial[i]));
                currentRoot->left = l;
                q.push(l);
            }
            i++;
            if (serial[i] != "null")
            {
                TreeNode *r = new TreeNode(stoi(serial[i]));
                currentRoot->right = r;
                q.push(r);
            }
            i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end
