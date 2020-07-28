/*
两数相加
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0;
        ListNode *cur1 = l1;
        ListNode *cur2 = l2;
        ListNode *head = new ListNode(0);
        ListNode *cur = head;
        while (cur1 && cur2)
        {
            int num = cur1->val + cur2->val + carry;
            carry = num / 10;
            int digit = num % 10;
            cur->next = new ListNode(digit);
            cur1 = cur1->next;
            cur2 = cur2->next;
            cur = cur->next;
        }
        while (cur1)
        {
            int num = cur1->val + carry;
            carry = num / 10;
            int digit = num % 10;
            cur->next = new ListNode(digit);
            cur1 = cur1->next;
            cur = cur->next;
        }
        while (cur2)
        {
            int num = cur2->val + carry;
            carry = num / 10;
            int digit = num % 10;
            cur->next = new ListNode(digit);
            cur2 = cur2->next;
            cur = cur->next;
        }
        if (carry)
        {
            cur->next = new ListNode(carry);
        }
        return head->next;
    }
};