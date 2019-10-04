/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */
#include <string>
#include <map>
#include <set>
#include <iostream>
using namespace std;

// @lc code=start
class Solution
{
public:
    /*
    first slide window solutions:
    */
    /*
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
*/

    // slide window solution with less code
    /* 
     p  w  w  k  e  w
     ij                         not find repeat, set add p, j++, update window size 1
     i  j                       not find repeat, set add w, j++, update window size 2
     i     j                    find repeat, delete p and move to next i
        i  j                    find repeat, delete w and move to next i
           ij                   no repeat, set add w (already there), j++, no need to update window size
           i  j                 no repeat, set add k, j++, no need to update window size
           i     j              no repeat, set add e, j++, update window size to 3
           i        j           find repeat, delete w and move to next i
              i        j        j out of bound, exit
                                return 3;
    */
    int lengthOfLongestSubstring(string s)
    {
        int i = 0;
        int j = 0;
        int max = 0;
        set<char> set;
        while (i < s.size() && j < s.size())
        {
            // find a repeat, this i ends
            if (set.find(s[j]) != set.end())
            {
                set.erase(s[i]);
                i++;
            }
            else // not find a repeat
            {
                set.insert(s[j]);
                j++;

                // update current max window size
                // j - i is the window
                if (j - i > max)
                {
                    max = j - i;
                }
            }
        }
        return max;
    }
};
// @lc code=end
