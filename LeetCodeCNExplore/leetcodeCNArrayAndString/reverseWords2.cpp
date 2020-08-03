/*
反转字符串中的单词 III
给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

示例 1:

输入: "Let's take LeetCode contest"
输出: "s'teL ekat edoCteeL tsetnoc" 
注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。
*/
#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        int wordStart = 0;
        int wordEnd = 0;
        while (wordEnd < s.size())
        {
            if (s[wordEnd] != ' ')
            {
                wordEnd++;
            }
            else
            {
                reverse(s, wordStart, wordEnd - 1);
                wordEnd++;
                wordStart = wordEnd;
            }
        }
        reverse(s, wordStart, wordEnd - 1); // reverse the last word
        return s;
    }
    void reverse(string &s, int start, int end)
    {
        while (start < end)
        {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
};

int main()
{
    string s = "Let's take LeetCode contest";
    Solution solution;
    cout << solution.reverseWords(s) << endl;
}