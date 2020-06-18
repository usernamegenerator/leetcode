/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (45.41%)
 * Likes:    3645
 * Dislikes: 396
 * Total Accepted:    584.9K
 * Total Submissions: 1.3M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * Note:
 * 
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */

// @lc code=start
class Solution
{
private:
    map<char, string> key = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    vector<string> ans;
    string current;
    void dfs(int index, string digits)
    {
        if (index == digits.size())
        {
            ans.push_back(current);
            return;
        }
        string thisDigitHas = key[digits[index]];
        for (int i = 0; i < thisDigitHas.size(); i++)
        {
            current.push_back(thisDigitHas[i]);
            dfs(index + 1, digits);
            current.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
        {
            return ans;
        }
        int index = 0;
        dfs(index, digits);
        return ans;
    }
};
// @lc code=end
