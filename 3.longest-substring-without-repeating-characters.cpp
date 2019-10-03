/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */
#include <string>
#include <map>
#include <iostream>
using namespace std;

// @lc code=start
class Solution
{
public:
    /*
brute force:
iterater through the string, start with the first
check if following have repeated.
store the res
*/
    int lengthOfLongestSubstring(string s)
    {
        if(s.empty())
            return 0;
        string maxString = " ";
        for (int i = 0; i < s.size(); i++)
        {
            string curString = "";
            curString.push_back(s[i]);
            for (int j = i + 1; j < s.size(); j++)
            {
                // found
                if (curString.find(s[j]) != string::npos)
                {
                    if (curString.size() > maxString.size())
                    {
                        maxString = curString;
                    }
                    break;
                }
                else // no found
                {
                    curString = curString + s[j];
                    if (curString.size() > maxString.size())
                    {
                        maxString = curString;
                    }
                }
            }
        }
        return maxString.size();
    }
};
// @lc code=end
