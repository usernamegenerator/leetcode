// https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/5/strings/36/
/*
  验证回文字符串
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true
示例 2:

输入: "race a car"
输出: false
*/
#include <string>
#include <cctype>
#include <iostream>
using namespace std;
class Solution
{
public:
    bool isPalindrome(string s)
    {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--)
        {
            while (!isalpha(s[i]) && !isdigit(s[i]) && i < j)
            {
                i++;
            }
            while (!isalpha(s[j]) && !isdigit(s[j]) && i < j)
            {
                j--;
            }
            // cout << i << " " << s[i] << " " << j << " " << s[j] << endl;
            if (tolower(s[i]) != tolower(s[j]))
                return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    // s.isPalindrome("A man, a plan, a canal: Panama");
    // cout << s.isPalindrome("0p") << endl;
    cout << s.isPalindrome("ab2a") << endl;
}
