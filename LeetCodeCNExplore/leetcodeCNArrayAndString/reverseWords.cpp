/*
翻转字符串里的单词
给定一个字符串，逐个翻转字符串中的每个单词。

 

示例 1：

输入: "the sky is blue"
输出: "blue is sky the"
示例 2：

输入: "  hello world!  "
输出: "world! hello"
解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
示例 3：

输入: "a good   example"
输出: "example good a"
解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 

说明：

无空格字符构成一个单词。
输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 

进阶：

请选用 C 语言的用户尝试使用 O(1) 额外空间复杂度的原地解法。
*/

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        int size = s.size();
        //////////////////////////////////////
        // reverse the whole string
        //////////////////////////////////////
        reverse(s, 0, size - 1);

        //////////////////////////////////////
        // reverse the word
        //////////////////////////////////////
        int start = 0;
        int end = 0;
        int i = 0;
        while (i < size)
        {
            if (s[i] != ' ')
            {
                start = i;
                end = i;
                while (s[end] != ' ' && end < size)
                {
                    end++;
                }
                reverse(s, start, end - 1);
                i = end;
            }
            else
            {
                i++;
            }
        }
        
        //////////////////////////////////////
        // remove the extra spaces
        //////////////////////////////////////
        start = 0; // track the location to be filled in
        end = 0;   // trace the valid chars, and copy it to the location of start
        bool spaceFound = false;
        while (s[end] == ' ' && end < size)
        {
            end++;
        } // end move to the 1st valid char;
        while (end < size)
        {
            if (s[end] != ' ') // if not spaces, just copy
            {
                s[start++] = s[end++];
                spaceFound = false;
            }
            else // if spaces
            {
                if (!spaceFound) // first time hit space, add a space
                {
                    s[start++] = ' ';
                    spaceFound = true;
                    end++;
                }
                else // not first time meaning there are many spaces, just continue;
                {
                    end++;
                }
            }
        }
        // remove the tailing spaces
        if (spaceFound) // if there is space found at last, s[start++] = ' '; statement will add extra space, so delete one more space
        {
            s.erase(s.begin() + start - 1, s.end());
        }
        else
        {
            s.erase(s.begin() + start, s.end());
        }

        return s;
    }

    void reverse(string &s, int left, int right)
    {
        while (left < right)
        {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};

int main()
{
    string s1 = "the sky is blue";
    string s2 = "  hello world!  ";
    string s3 = "a good   example";
    Solution solution;
    solution.reverseWords(s1);
    cout << endl;
    solution.reverseWords(s2);
    cout << endl;
    solution.reverseWords(s3);
}