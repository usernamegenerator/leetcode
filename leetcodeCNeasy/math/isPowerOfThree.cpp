// https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/25/math/62/

/*
3的幂
给定一个整数，写一个函数来判断它是否是 3 的幂次方。

示例 1:

输入: 27
输出: true
示例 2:

输入: 0
输出: false
示例 3:

输入: 9
输出: true
示例 4:

输入: 45
输出: false
进阶：
你能不使用循环或者递归来完成本题吗？
*/

class Solution
{
public:
    /*
    bool isPowerOfThree(int n)
    {
        if (n == 0)
            return false;
        int temp = n;
        while (temp != 1)
        {
            if (temp % 3 != 0)
            {
                return false;
            }
            temp = temp / 3;
        }
        return true;
    }
*/
    bool isPowerOfThree(int n)
    {
        // pow(3, 19) is the max power of three in the integer range
        return (n > 0 && (((int)pow(3, 19) % n) == 0));
    }
};