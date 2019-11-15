/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (34.19%)
 * Likes:    1719
 * Dislikes: 1537
 * Total Accepted:    578.9K
 * Total Submissions: 1.7M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */

// @lc code=start
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";

        int count = 0;
        string res = "";
        for (int i = 0; i < strs[0].size(); i++)
        {
            char compare = strs[0][i];
            bool allSame = true;

            for (int j = 1; j < strs.size(); j++)
            {
                if (strs[j][i] != compare)
                {
                    allSame = false;
                    return res;
                }
            }
            if (allSame == true)
            {
                res += strs[0][i];
            }
        }
        return res;
    }
};
// @lc code=end
