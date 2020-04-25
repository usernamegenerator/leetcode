// https://leetcode-cn.com/explore/interview/card/top-interview-questions-medium/31/linked-list/84/
// https://leetcode-cn.com/problems/intersection-of-two-linked-lists/solution/xiang-jiao-lian-biao-by-leetcode/

#include <unordered_map>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_map<ListNode *, bool> um;
        ListNode *iterA = headA;
        while (iterA != NULL)
        {
            um.insert(make_pair(iterA, true));
            iterA = iterA->next;
        }
        ListNode *iterB = headB;
        while (iterB != NULL)
        {
            if (um.find(iterB) != um.end())
            {
                return iterB;
            }
            iterB = iterB->next;
        }
        return NULL;
    }
};
*/
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *iterA = headA;
        ListNode *iterB = headB;
        if (iterA == NULL || iterB == NULL)
            return NULL;
        while (iterA != iterB)
        {
            iterA = iterA->next;
            iterB = iterB->next;
            if (iterA == NULL && iterB == NULL)
                return NULL;
            if (iterA == NULL)
            {
                iterA = headB;
            }
            if (iterB == NULL)
            {
                iterB = headA;
            }
        }
        return iterA;
    }
};