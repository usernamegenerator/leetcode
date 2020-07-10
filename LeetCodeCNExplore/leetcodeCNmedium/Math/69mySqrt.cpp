/*
x 的平方根
实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:

输入: 4
输出: 2
示例 2:

输入: 8
输出: 2
说明: 8 的平方根是 2.82842..., 
     由于返回类型是整数，小数部分将被舍去。
*/
class Solution
{
public:
    int mySqrt(int x)
    {
        if (x < 2)
            return x;
        // newton method
        double x0 = x;
        double x1 = (x0 + x / x0) / 2.0;
        while (abs(x0 - x1) >= 1)
        {
            x0 = x1;
            x1 = x1 = (x0 + x / x0) / 2.0;
        }
        return (int)x1;
    }
};