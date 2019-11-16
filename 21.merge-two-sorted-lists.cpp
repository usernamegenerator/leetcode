/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (49.14%)
 * Likes:    2904
 * Dislikes: 420
 * Total Accepted:    746.7K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 * 
 * 
 */

// @lc code=start
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
        ListNode *head = new ListNode(-1);
        ListNode *p = head;
        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val < l2->val)
            {
                p->next = new ListNode(l1->val);
                l1 = l1->next;
                p = p->next;
            }
            else
            {
                p->next = new ListNode(l2->val);
                l2 = l2->next;
                p = p->next;
            }
        }
        while (l1 != NULL)
        {
            p->next = new ListNode(l1->val);
            l1 = l1->next;
            p = p->next;
        }
        while (l2 != NULL)
        {
            p->next = new ListNode(l2->val);
            l2 = l2->next;
            p = p->next;
        }
        return head->next;
    }
};
// @lc code=end
