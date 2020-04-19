#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (55.11%)
 * Likes:    3093
 * Dislikes: 166
 * Total Accepted:    620.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings, group anagrams together.
 * 
 * Example:
 * 
 * 
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Output:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * Note:
 * 
 * 
 * All inputs will be in lowercase.
 * The order of your output does not matter.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> um;
        vector<vector<string>> res;
        for (int i = 0; i < strs.size(); i++)
        {
            string sorted = strs[i];
            sort(sorted.begin(), sorted.end());
            unordered_map<string, vector<string>>::iterator it = um.find(sorted);
            // didn't find
            if (it == um.end())
            {
                vector<string> string_vec;
                string_vec.push_back(strs[i]);
                um.insert(make_pair(sorted, string_vec));
            }
            else //find
            {
                it->second.push_back(strs[i]);
            }
        }

        for (unordered_map<string, vector<string>>::iterator jt = um.begin(); jt != um.end(); jt++)
        {
            res.push_back(jt->second);
        }

        return res;
    }
};
// @lc code=end
