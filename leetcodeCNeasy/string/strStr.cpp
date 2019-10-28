// https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/5/strings/38/

/*
实现 strStr()
实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1:

输入: haystack = "hello", needle = "ll"
输出: 2
示例 2:

输入: haystack = "aaaaa", needle = "bba"
输出: -1
说明:

当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
*/
#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.empty())
        {
            return 0;
        }
        if (haystack.empty())
        {
            return -1;
        }

        int idx = -1;
        int j = 0;
        for (int i = 0; i < haystack.size(); i++)
        {
            if (haystack[i] != needle[j])
            {
                continue;
            }
            else
            {
                idx = i;
                while (haystack[i] == needle[j] && i < haystack.size() && j < needle.size())
                {
                    i++;
                    j++;
                }
                if (j == needle.size())
                {
                    return idx;
                }
                else
                {
                    //reset
                    j = 0;
                    i = idx;
                    idx = -1;
                }
            }
        }
        return idx;
    }
};

int main()
{
    // string haystack = "hello", needle = "ll";
    // string haystack = "aaaaa", needle = "bba";
    // string haystack = "aaaaa", needle = "a";
    string haystack = "mississippi", needle = "issip";

    Solution s;
    cout << s.strStr(haystack, needle) << endl;
}