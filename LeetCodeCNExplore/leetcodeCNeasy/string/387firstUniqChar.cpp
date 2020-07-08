// https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/5/strings/34/
/*
  字符串中的第一个唯一字符
给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

案例:

s = "leetcode"
返回 0.

s = "loveleetcode",
返回 2.
 

注意事项：您可以假定该字符串只包含小写字母。
*/
#include <string>
using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        int numOfOccurance[26] = {0};
        for (int i = 0; i < s.size(); i++)
        {
            numOfOccurance[s[i] - 'a']++;
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (numOfOccurance[s[i] - 'a'] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};