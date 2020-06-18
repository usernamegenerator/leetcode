/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (60.66%)
 * Likes:    4892
 * Dislikes: 259
 * Total Accepted:    530.6K
 * Total Submissions: 862.2K
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 */

// @lc code=start
class Solution
{
private:
    vector<string> res;
    void backtrace(int numOfLeft, int numOfRight, string current)
    {
        if (numOfLeft == 0 && numOfRight == 0)
        {
            res.push_back(current);
            return;
        }
        if (numOfLeft > 0)
        {
            backtrace(numOfLeft - 1, numOfRight, current + "(");
        }
        if (numOfRight > numOfLeft)
        {
            backtrace(numOfLeft, numOfRight - 1, current + ")");
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        int numOfLeft = n;
        int numOfRight = n;
        string current = "";
        backtrace(numOfLeft, numOfRight, current);
        return res;
    }
};
// @lc code=end
