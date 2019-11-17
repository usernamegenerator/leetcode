/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 *
 * https://leetcode.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (38.97%)
 * Likes:    2284
 * Dislikes: 245
 * Total Accepted:    372.2K
 * Total Submissions: 938.8K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 * 
 * 
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 * 
 * 
 * 
 * 
 */

// @lc code=start
class MinStack
{
    stack<int> data;
    stack<int> min;

public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        data.push(x);
        if (min.empty())
        {
            min.push(x);
        }
        else if (min.top() < x)
        {
            min.push(min.top());
        }
        else
        {
            min.push(x);
        }
    }

    void pop()
    {
        if (data.empty())
            return;
        min.pop();
        data.pop();
    }

    int top()
    {
        return data.top();
    }

    int getMin()
    {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
