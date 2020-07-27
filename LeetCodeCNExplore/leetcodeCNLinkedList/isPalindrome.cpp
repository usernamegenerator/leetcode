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
    void printList(ListNode *head)
    {
        ListNode *cur = head;
        while (cur)
        {
            cout << cur->val << " -> ";
            cur = cur->next;
        }
        cout << endl;
    }
    bool isPalindrome(ListNode *head)
    {
        if (head == nullptr)
        {
            return true;
        }
        if (head->next == nullptr)
        {
            return true;
        }
        // count
        ListNode *cur = head;
        int count = 0;
        while (cur)
        {
            cur = cur->next;
            count++;
        }

        // find head
        ListNode *firstHead = head;
        ListNode *secondHead = head;
        int iter = count / 2 - 1;
        while (iter--)
        {

            firstHead = firstHead->next;
        }
        if (count % 2 == 0) // even
        {
            secondHead = firstHead->next;
        }
        else
        {
            secondHead = firstHead->next->next;
        }

        //cout << firstHead->val << endl;
        //cout << secondHead->val << endl;
        //cout << "reverse first half" << endl;

        // reverse first half
        cur = head;
        ListNode *pre = nullptr;
        ListNode *nex = cur;
        while (pre != firstHead)
        {
            nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        //cout << pre->val << endl;
        //cout << firstHead->val << endl;
        //cout << "iterate and compare" << endl;
        // iterate and compare
        ListNode *iter1 = firstHead;
        ListNode *iter2 = secondHead;
        while (iter1 && iter2)
        {
            //cout << iter1->val << " " << iter2->val << endl;
            if (iter1->val != iter2->val)
            {
                return false;
            }
            iter1 = iter1->next;
            iter2 = iter2->next;
        }
        return true;
    }
};

int main()
{
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    //head->next->next->next->next = new ListNode(1);
    //s.printList(head);
    cout << s.isPalindrome(head) << endl;
}