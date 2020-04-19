/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 *
 * https://leetcode.com/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (42.32%)
 * Likes:    1737
 * Dislikes: 281
 * Total Accepted:    288.8K
 * Total Submissions: 682.2K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * Given a m x n matrix, if an element is 0, set its entire row and column to
 * 0. Do it in-place.
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * [
 * [1,1,1],
 * [1,0,1],
 * [1,1,1]
 * ]
 * Output: 
 * [
 * [1,0,1],
 * [0,0,0],
 * [1,0,1]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * [
 * [0,1,2,0],
 * [3,4,5,2],
 * [1,3,1,5]
 * ]
 * Output: 
 * [
 * [0,0,0,0],
 * [0,4,5,0],
 * [0,3,1,0]
 * ]
 * 
 * 
 * Follow up:
 * 
 * 
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best
 * solution.
 * Could you devise a constant space solution?
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int zeroRow = 0;
        int zeroCol = 0;
        bool foundZero = false;
        for (int row = 0; row < m; row++)
        {
            if (foundZero)
                break;
            for (int col = 0; col < n; col++)
            {
                if (matrix[row][col] == 0)
                {
                    foundZero = true;
                    zeroRow = row;
                    zeroCol = col;
                    break;
                }
            }
        }
        if (foundZero == false)
            return;

        // after found the coordinator row and col
        // set the coordinator to 0 accordingly
        for (int row = 0; row < m; row++)
        {
            if (row == zeroRow)
                continue;
            for (int col = 0; col < n; col++)
            {
                if (col == zeroCol)
                    continue;
                if (matrix[row][col] == 0)
                {
                    matrix[zeroRow][col] = 0;
                    matrix[row][zeroCol] = 0;
                }
            }
        }

        for (int row = 0; row < m; row++)
        {
            if (row == zeroRow)
                continue;
            if (matrix[row][zeroCol] == 0)
            {
                for (int col = 0; col < n; col++)
                {
                    matrix[row][col] = 0;
                }
            }
        }
        for (int col = 0; col < n; col++)
        {
            if (col == zeroCol)
                continue;
            if (matrix[zeroRow][col] == 0)
            {
                for (int row = 0; row < m; row++)
                {
                    matrix[row][col] = 0;
                }
            }
        }
        for (int col = 0; col < n; col++)
        {
            matrix[zeroRow][col] = 0;
        }
        for (int row = 0; row < m; row++)
        {
            matrix[row][zeroCol] = 0;
        }
    }
};
// @lc code=end
