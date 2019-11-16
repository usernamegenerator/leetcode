/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (37.13%)
 * Likes:    2095
 * Dislikes: 298
 * Total Accepted:    318.8K
 * Total Submissions: 853.5K
 * Testcase Example:  '[1,2]'
 *
 * Given a singly linked list, determine if it is a palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2
 * Output: false
 * 
 * Example 2:
 * 
 * 
 * Input: 1->2->2->1
 * Output: true
 * 
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
 * 
 */
#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
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
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return true;
        ListNode *p = head;
        // count how many elements in the linked list
        int count = 0;
        while (p != NULL)
        {
            count++;
            p = p->next;
        }
        // find the first half index and the second half index
        int firstHalfIdx = count / 2 - 1;
        int secondHalfIdx;
        if (count % 2)
        {
            secondHalfIdx = firstHalfIdx + 2;
        }
        else
        {
            secondHalfIdx = firstHalfIdx + 1;
        }

        //cout << firstHalfIdx << endl;
        //cout << secondHalfIdx << endl;

        // get second half pointer
        ListNode *secondHalfHead = head;
        while (secondHalfIdx--)
        {
            secondHalfHead = secondHalfHead->next;
        }

        // get first half pointer
        p = head;
        while (firstHalfIdx--)
        {
            p = p->next;
        }

        //cout << " to " << p->val << endl;
        ListNode *firstHalfHead = reverse(head, p);

        //cout << firstHalfHead->val << endl;
        //cout << secondHalfHead->val << endl;

        // iterate both half through and compare
        while (secondHalfHead != NULL)
        {
            if (secondHalfHead->val != firstHalfHead->val)
            {
                return false;
            }
            firstHalfHead = firstHalfHead->next;
            secondHalfHead = secondHalfHead->next;
        }
        return true;
    }

    ListNode *reverse(ListNode *head, ListNode *to)
    {
        //cout << "reverse" << endl;
        //cout << to->next << endl;
        // to is the new head;
        ListNode *end = to->next; // must save to->next to use for compare
        ListNode *cur = head;
        ListNode *nex = NULL;
        ListNode *pre = NULL;
        while (cur != end)
        {
            //cout << cur << " " << to->next << endl;
            nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        //cout << "reverse done " << pre->val << endl;
        return pre;
    }
};
// @lc code=end

int main()
{
    ListNode *head = new ListNode(1);
    //head->next = new ListNode(1);
    //head->next->next = new ListNode(2);
    //head->next->next->next = new ListNode(2);
    //head->next->next->next->next = new ListNode(1);
    Solution s;
    cout << "return " << s.isPalindrome(head) << endl;
}