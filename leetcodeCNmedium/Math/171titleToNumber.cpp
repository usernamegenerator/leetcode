/*
Excel表列序号
给定一个Excel表格中的列名称，返回其相应的列序号。

例如，

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...
示例 1:

输入: "A"
输出: 1
示例 2:

输入: "AB"
输出: 28
示例 3:

输入: "ZY"
输出: 701
致谢：
特别感谢 @ts 添加此问题并创建所有测试用例。
*/

class Solution
{
private:
    int charToInt(char c)
    {
        return c - 'A' + 1;
    }

public:
    // 26进制
    int titleToNumber(string s)
    {
        unsigned long long pos = 1;
        int sum = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            sum += charToInt(s[i]) * pos;
            pos = pos * 26;
        }
        return sum;
    }
};