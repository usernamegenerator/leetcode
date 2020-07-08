// https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/6/linked-list/44/
/*
合并两个有序链表
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {

        ListNode *head = new ListNode(0); // dummy head
        ListNode *cur = head;
        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val < l2->val)
            {
                cur->next = new ListNode(l1->val);
                l1 = l1->next;
                cur = cur->next;
            }
            else
            {
                cur->next = new ListNode(l2->val);
                l2 = l2->next;
                cur = cur->next;
            }
        }
        while (l1 != NULL)
        {
            cur->next = new ListNode(l1->val);
            l1 = l1->next;
            cur = cur->next;
        }
        while (l2 != NULL)
        {
            cur->next = new ListNode(l2->val);
            l2 = l2->next;
            cur = cur->next;
        }
        return head->next;
    }
};