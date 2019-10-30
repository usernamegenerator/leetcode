// https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/6/linked-list/42/

/*
 删除链表的倒数第N个节点
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *first = head;
        ListNode *second = head;
        int advance = n;
        while (advance--)
        {
            second = second->next;
        }
        // second is NULL after moving
        // the node to delete is the head
        if(second == NULL)
            return first->next;
            
        while (second->next != NULL)
        {
            second = second->next;
            first = first->next;
        }

        // skip the node to be deleted
        first->next = first->next->next;

        return head;
    }
};