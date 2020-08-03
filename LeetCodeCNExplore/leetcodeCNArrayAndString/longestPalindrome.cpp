/*
最长回文子串
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"
*/

class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.size() == 0)
            return "";
        string res;
        for (int i = 0; i < s.size(); i++)
        {
            string str1 = expandFromCenter(i, i, s);
            string str2 = expandFromCenter(i, i + 1, s);
            string maxstr = (str1.size() > str2.size()) ? str1 : str2;
            if (maxstr.size() > res.size())
            {
                res = maxstr;
            }
        }
        return res;
    }
    string expandFromCenter(int leftIdx, int rightIdx, string s)
    {
        if (rightIdx >= s.size())
            return "";
        while (rightIdx < s.size() && leftIdx >= 0 && s[leftIdx] == s[rightIdx])
        {
            leftIdx--;
            rightIdx++;
        }
        leftIdx++;
        rightIdx--;
        return s.substr(leftIdx, rightIdx - leftIdx + 1);
    }
};