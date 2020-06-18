/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 *
 * https://leetcode.com/problems/excel-sheet-column-number/description/
 *
 * algorithms
 * Easy (53.59%)
 * Likes:    922
 * Dislikes: 152
 * Total Accepted:    283.1K
 * Total Submissions: 523.5K
 * Testcase Example:  '"A"'
 *
 * Given a column title as appear in an Excel sheet, return its corresponding
 * column number.
 * 
 * For example:
 * 
 * 
 * ⁠   A -> 1
 * ⁠   B -> 2
 * ⁠   C -> 3
 * ⁠   ...
 * ⁠   Z -> 26
 * ⁠   AA -> 27
 * ⁠   AB -> 28 
 * ⁠   ...
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "A"
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "AB"
 * Output: 28
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "ZY"
 * Output: 701
 * 
 */

// @lc code=start
class Solution
{
public:
    int titleToNumber(string s)
    {
        int position = s.size() - 1;
        int sum = 0;
        for (int i = 0; i < s.size(); i++)
        {
            sum += (s[i] - 'A' + 1) * pow(26, position);
            position--;
        }
        return sum;
    }
};
// @lc code=end
