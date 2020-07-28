/*
合并两个有序链表
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr)
        {
            return l2;
        }
        if (l2 == nullptr)
        {
            return l1;
        }
        ListNode *cur1 = l1;
        ListNode *cur2 = l2;
        ListNode *head = new ListNode(0); // dummy head
        ListNode *cur = head;
        while (cur1 && cur2)
        {
            if (cur1->val > cur2->val)
            {
                cur->next = new ListNode(cur2->val);
                cur2 = cur2->next;
                cur = cur->next;
            }
            else
            {
                cur->next = new ListNode(cur1->val);
                cur1 = cur1->next;
                cur = cur->next;
            }
        }
        while (cur1)
        {
            cur->next = new ListNode(cur1->val);
            cur1 = cur1->next;
            cur = cur->next;
        }
        while (cur2)
        {
            cur->next = new ListNode(cur2->val);
            cur2 = cur2->next;
            cur = cur->next;
        }
        
        return head->next;
    }
};