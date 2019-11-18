/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (48.13%)
 * Likes:    921
 * Dislikes: 84
 * Total Accepted:    305.1K
 * Total Submissions: 625.6K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 5
 * Output:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        if (numRows == 0)
            return {};
        vector<vector<int>> res;
        res.push_back({1});
        if (numRows == 1)
        {
            return res;
        }
        res.push_back({1, 1});
        if (numRows == 2)
        {
            return res;
        }

        for (int rowIdx = 2; rowIdx < numRows; rowIdx++)
        {
            int size = rowIdx + 1;
            vector<int> thisRow(size, 0);
            vector<int> preRow = res[rowIdx - 1];
            thisRow[0] = 1;
            thisRow[size - 1] = 1;
            for (int i = 1; i < size - 1; i++)
            {
                thisRow[i] = preRow[i - 1] + preRow[i];
            }
            res.push_back(thisRow);
        }

        return res;
    }
};
// @lc code=end
