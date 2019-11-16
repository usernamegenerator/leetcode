// https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/6/linked-list/45/

/*
回文链表
请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true
进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
*/
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        // 1. iterate through to find the number of elements and find the middle
        // 2. reverse the first part
        // 3. iterate from the middle to both end and compare

        // 1
        ListNode *cur = head;
        int cnt = 0;
        while (cur)
        {
            cur = cur->next;
            cnt++;
        }

        int middle = cnt / 2;

        ListNode *middleNode = head;

        while (middle--)
        {
            middleNode = middleNode->next;
        }

        // 2
        ListNode *pre = NULL;
        ListNode *nex = NULL;
        cur = head;
        while (cur != middleNode)
        {
            nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }

        /* cout << pre->val << endl;
        cout << cur->val << endl;
        cout << cur->next->val << endl; */
        

        ListNode *leftHead = NULL;
        ListNode *rightHead = NULL;
        if (cnt % 2)
        {
            leftHead = pre;
            // cur is the center
            rightHead = cur->next;
        }
        else
        {
            leftHead = pre;
            rightHead = cur;
        }
        // 3
        ListNode *left = leftHead;
        ListNode *right = rightHead;

        while (right != NULL)
        {
            // cout << right->val << " " << left->val << endl;
            if (right->val != left->val)
            {
                return false;
            }
            right = right->next;
            left = left->next;
        }
        return true;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    // head->next->next->next->next = new ListNode(1);
    Solution s;
    cout << s.isPalindrome(head) << endl;
}