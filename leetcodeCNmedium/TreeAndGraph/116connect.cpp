// https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == NULL)
            return NULL;
        queue<Node *> levelQueue;
        levelQueue.push(root);
        int thisLevelCount = 1;
        int nextLevelCount = 0;
        while (!levelQueue.empty())
        {
            vector<Node *> thisLevelVector;
            for (int i = 0; i < thisLevelCount; i++)
            {
                Node *temp = levelQueue.front();
                thisLevelVector.push_back(temp);
                levelQueue.pop();
                if (temp->left)
                {
                    levelQueue.push(temp->left);
                    nextLevelCount++;
                }
                if (temp->right)
                {
                    levelQueue.push(temp->right);
                    nextLevelCount++;
                }
            }
            for (int i = 0; i < thisLevelCount - 1; i++)
            {
                thisLevelVector[i]->next = thisLevelVector[i + 1];
            }
            thisLevelVector[thisLevelCount - 1]->next = NULL;

            thisLevelCount = nextLevelCount;
            nextLevelCount = 0;
        }

        return root;
    }
};