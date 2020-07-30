/*
旋转链表
给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL
示例 2:

输入: 0->1->2->NULL, k = 4
输出: 2->0->1->NULL
解释:
向右旋转 1 步: 2->0->1->NULL
向右旋转 2 步: 1->2->0->NULL
向右旋转 3 步: 0->1->2->NULL
向右旋转 4 步: 2->0->1->NULL
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL)
            return head;
        if (k == 0)
            return head;
        int count = 0;
        ListNode *cur = head;
        while (cur)
        {
            count++;
            cur = cur->next;
        }
        if(count == 1)
        {
            return head;
        }
        int moveRight = count - k % count;
        if(moveRight == 0 || (k % count == 0))
        {
            return head;
        }
        ListNode *newHead = head;
        while (moveRight--)
        {
            newHead = newHead->next;
        }
        cur = newHead;
        while (cur->next)
        {
            cur = cur->next;
        }
        cur->next = head;
        while (cur->next != newHead)
        {
            cur = cur->next;
        }
        cur->next = NULL;
        return newHead;
    }
};