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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *i = l1;
        ListNode *j = l2;
        ListNode *head = new ListNode(0);
        ListNode *res = head;
        int carry = 0;
        while (i != NULL && j != NULL)
        {
            int sum = i->val + j->val + carry;
            int digit = sum % 10;
            head->next = new ListNode(digit);
            carry = sum / 10;
            i = i->next;
            j = j->next;
            head = head->next;
        }
        while (i != NULL)
        {
            int sum = i->val + carry;
            int digit = sum % 10;
            head->next = new ListNode(digit);
            carry = sum / 10;
            i = i->next;
            head = head->next;
        }
        while (j != NULL)
        {
            int sum = j->val + carry;
            int digit = sum % 10;
            head->next = new ListNode(digit);
            carry = sum / 10;
            j = j->next;
            head = head->next;
        }
        if (carry != 0)
        {
            head->next = new ListNode(carry);
        }
        return res->next;
    }
};