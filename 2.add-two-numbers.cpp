/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (31.18%)
 * Likes:    5251
 * Dislikes: 1351
 * Total Accepted:    888.7K
 * Total Submissions: 2.9M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example:
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 * 
 * 
 */
#include <cstddef>
#include <vector>
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        vector<int> res;
        ListNode *head1 = l1;
        ListNode *head2 = l2;

        bool carry = 0;
        int singleDigitRes = 0;
        while (head1 != NULL && head2 != NULL)
        {
            if (head1->val + head2->val + carry >= 10)
            {
                singleDigitRes = (head1->val + head2->val + carry) % 10;
                carry = 1;
            }
            else
            {
                singleDigitRes = (head1->val + head2->val + carry);
                carry = 0;
            }
            res.push_back(singleDigitRes);

            head1 = head1->next;
            head2 = head2->next;
        }

        while (head1 != NULL)
        {
            if (head1->val + carry >= 10)
            {
                singleDigitRes = (head1->val + carry) % 10;
                carry = 1;
            }
            else
            {
                singleDigitRes = head1->val + carry;
                carry = 0;
            }
            res.push_back(singleDigitRes);
            head1 = head1->next;
        }

        while (head2 != NULL)
        {
            if (head2->val + carry >= 10)
            {
                singleDigitRes = (head2->val + carry) % 10;
                carry = 1;
            }
            else
            {
                singleDigitRes = head2->val + carry;
                carry = 0;
            }
            res.push_back(singleDigitRes);
            head2 = head2->next;
        }

        // the MSB add results in a carry, need to add one more digit
        if (carry)
        {
            res.push_back(1);
        }
        
        ListNode *preNode = new ListNode(res[0]);
        preNode->next = NULL;
        ListNode *output = preNode;
        for (vector<int>::iterator it = res.begin() + 1; it != res.end(); it++)
        {
            ListNode *curNode = new ListNode(*it);
            curNode->next = NULL;
            preNode->next = curNode;
            preNode = curNode;
        }

        return output;
    }
};
// @lc code=end
