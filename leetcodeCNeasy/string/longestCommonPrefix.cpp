// https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/5/strings/40/

/*
最长公共前缀
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 。
*/
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if(strs.empty)
            return "";
        string first = strs[0];
        string res = "";
        for (int i = 0; i < first.size(); i++)
        {

            int j = 1;
            while (j < strs.size())
            {
                string str = strs[j];
                if (i >= str.size())
                    return res;
                if (first[i] != str[i])
                {
                    return res;
                }
                j++;
            }
            // if (j == strs.size()) // this has to be true
            {
                res += first[i];
            }
        }
        return res;
    }
};

int main()
{
    // vector<string> strs{"flower","flow","flight"};
    // vector<string> strs{"dog", "racecar", "car"};
    vector<string> strs{"flower","flow","f"};
    Solution s;
    cout << s.longestCommonPrefix(strs) << endl;
}