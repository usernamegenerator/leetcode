/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (53.68%)
 * Likes:    926
 * Dislikes: 121
 * Total Accepted:    423.7K
 * Total Submissions: 782.6K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t , write a function to determine if t is an anagram
 * of s.
 * 
 * Example 1:
 * 
 * 
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "rat", t = "car"
 * Output: false
 * 
 * 
 * Note:
 * You may assume the string contains only lowercase alphabets.
 * 
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your
 * solution to such case?
 * 
 */

// @lc code=start
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int num[26] = {0};
        for (int i = 0; i < s.size(); i++)
        {
            num[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++)
        {
            num[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (num[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
