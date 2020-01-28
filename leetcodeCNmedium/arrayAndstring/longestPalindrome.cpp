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

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // method 1:
    // iterate through the array, use the index to expand
    string longestPalindrome(string s)
    {
        string res;
        for (int i = 0; i < s.size(); i++)
        {
            //1 center
            string s1 = centerExpand(s, i, i);
            //2 center
            string s2 = centerExpand(s, i, i + 1);
            if (s1.size() > res.size())
            {
                res = s1;
            }
            if (s2.size() > res.size())
            {
                res = s2;
            }
        }
        return res;
    }
    string centerExpand(string s, int leftCenter, int rightCenter)
    {
        int left = leftCenter;
        int right = rightCenter;
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }
        // need to compensate
        left++;
        right--;
        return s.substr(left, right - left + 1);
    }
};