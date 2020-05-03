/*
两整数之和
不使用运算符 + 和 - ​​​​​​​，计算两整数 ​​​​​​​a 、b ​​​​​​​之和。

示例 1:

输入: a = 1, b = 2
输出: 3
示例 2:

输入: a = -2, b = 3
输出: 1
*/

class Solution
{
public:
    int getSum(int a, int b)
    {
        int add;
        unsigned int carry;
        while (b != 0)
        {
            add = a ^ b;
            carry = a & b;
            a = add;
            b = carry << 1;
        }
        return a;
    }
};