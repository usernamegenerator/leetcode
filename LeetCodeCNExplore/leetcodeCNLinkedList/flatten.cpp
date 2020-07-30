/*
扁平化多级双向链表
多级双向链表中，除了指向下一个节点和前一个节点指针之外，它还有一个子链表指针，可能指向单独的双向链表。这些子列表也可能会有一个或多个自己的子项，依此类推，生成多级数据结构，如下面的示例所示。

给你位于列表第一级的头节点，请你扁平化列表，使所有结点出现在单级双链表中。

 

示例 1：

输入：head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
输出：[1,2,3,7,8,11,12,9,10,4,5,6]
解释：

输入的多级列表如下图所示：



扁平化后的链表如下图：


示例 2：

输入：head = [1,2,null,3]
输出：[1,3,2]
解释：

输入的多级列表如下图所示：

  1---2---NULL
  |
  3---NULL
示例 3：

输入：head = []
输出：[]
 

如何表示测试用例中的多级链表？

以 示例 1 为例：

 1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL
序列化其中的每一级之后：

[1,2,3,4,5,6,null]
[7,8,9,10,null]
[11,12,null]
为了将每一级都序列化到一起，我们需要每一级中添加值为 null 的元素，以表示没有节点连接到上一级的上级节点。

[1,2,3,4,5,6,null]
[null,null,7,8,9,10,null]
[null,11,12,null]
合并所有序列化结果，并去除末尾的 null 。

[1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
 

提示：

节点数目不超过 1000
1 <= Node.val <= 10^5
*/
#include <stack>
#include <iostream>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution
{
private:
    stack<Node *> nodeStack;

public:
    Node *flatten(Node *head)
    {
        if (head == NULL)
            return NULL;
        Node *newHead = new Node();
        newHead->val = head->val;
        newHead->next = NULL;
        newHead->child = NULL;
        newHead->prev = NULL;
        Node *newCur = newHead;
        Node *cur = head;
        while (cur)
        {
            if (cur->child) // has a child branch, go child
            {
                if (cur->next) // save the next to come back
                {
                    nodeStack.push(cur->next);
                }
                newCur->next = new Node();
                newCur->next->val = cur->child->val;
                newCur->next->prev = newCur;
                newCur = newCur->next;
                newCur->next = NULL;
                newCur->child = NULL;
                
                cur = cur->child;
            }
            else // doesn't have a child branch, go next
            {
                if (!cur->next) // if next is NULL
                {
                    if (!nodeStack.empty()) // if there are elements in the stack
                    {
                        newCur->next = new Node();
                        Node *stackTop = nodeStack.top();
                        nodeStack.pop();
                        newCur->next->val = stackTop->val;
                        newCur->next->prev = newCur;
                        newCur = newCur->next;
                        newCur->next = NULL;
                        newCur->child = NULL;
                        cur = stackTop;
                    }
                    else // if there is no element in the stack, end
                    {
                        return newHead;
                    }
                }
                else // if next still valid, go next
                {
                    newCur->next = new Node();
                    newCur->next->val = cur->next->val;
                    newCur->next->prev = newCur;
                    newCur = newCur->next;
                    newCur->next = NULL;
                    newCur->child = NULL;
                    cur = cur->next;
                }
            }
        }
        return newHead;
    }
};

int main()
{
    Solution s;
    /*
    Node *head = new Node();
    head->val = 1;
    head->next = new Node();
    head->next->val = 2;
    head->child = new Node();
    head->child->val = 3;
    */

    Node *head = new Node();
    head->val = 1;
    head->next = new Node();
    head->next->val = 2;
    head->next->next = new Node();
    head->next->next->val = 3;
    head->next->next->next = new Node();
    head->next->next->next->val = 4;
    head->next->next->next->next = new Node();
    head->next->next->next->next->val = 5;
    head->next->next->next->next->next = new Node();
    head->next->next->next->next->next->val = 6;

    head->next->next->child = new Node();
    head->next->next->child->val = 7;
    head->next->next->child->next = new Node();
    head->next->next->child->next->val = 8;
    head->next->next->child->next->next = new Node();
    head->next->next->child->next->next->val = 9;
    head->next->next->child->next->next->next = new Node();
    head->next->next->child->next->next->next->val = 10;

    head->next->next->child->next->child = new Node();
    head->next->next->child->next->child->val = 11;
    head->next->next->child->next->child->next = new Node();
    head->next->next->child->next->child->next->val = 12;

    Node *newHead = s.flatten(head);
    Node *cur = newHead;
    while (cur)
    {
        cout << cur->val << "-->";
        cur = cur->next;
    }
}