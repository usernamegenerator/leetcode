// https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/24/design/59/

/*
最小栈
设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。

push(x) -- 将元素 x 推入栈中。
pop() -- 删除栈顶的元素。
top() -- 获取栈顶元素。
getMin() -- 检索栈中的最小元素。
示例:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.
*/

class MinStack
{
public:
    /** initialize your data structure here. */
    stack<int> data;
    stack<int> min;
    MinStack()
    {
    }

    void push(int x)
    {
        if (data.empty())
        {
            data.push(x);
            min.push(x);
        }
        else
        {
            data.push(x);
            int minTop = min.top();
            if (x < minTop)
            {
                min.push(x);
            }
            else
            {
                min.push(minTop);
            }
        }
    }

    void pop()
    {
        if (data.empty())
            return;

        data.pop();
        min.pop();
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