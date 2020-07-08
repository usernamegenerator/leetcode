/*
无重复字符的最长子串
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/

#include <iostream>
#include <set>
using namespace std;

// 就用双指针法。
// i从头数， j从i后面一个开始数
// 用一个set来保存[i,j]
// 如果新的j在[i,j]里没有重复，就加进去，count+1
// 如果有重复，就break出来。从下一个i开始数起
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.empty())
        {
            return 0;
        }
        int max = -1;
        for (int i = 0; i < s.size(); i++)
        {
            set<char> st;
            int count = 0;
            st.insert(s[i]);
            count++;
            for (int j = i + 1; j < s.size(); j++)
            {
                if (st.find(s[j]) != st.end())
                {
                    break;
                }
                else
                {
                    st.insert(s[j]);
                    count++;
                }
            }
            if (count > max)
            {
                max = count;
            }
        }

        return max;
    }
};
