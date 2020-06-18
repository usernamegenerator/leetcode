/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 *
 * https://leetcode.com/problems/search-a-2d-matrix-ii/description/
 *
 * algorithms
 * Medium (42.58%)
 * Likes:    2943
 * Dislikes: 75
 * Total Accepted:    306.1K
 * Total Submissions: 714.5K
 * Testcase Example:  '[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n5'
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 * 
 * 
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 * 
 * 
 * Example:
 * 
 * Consider the following matrix:
 * 
 * 
 * [
 * ⁠ [1,   4,  7, 11, 15],
 * ⁠ [2,   5,  8, 12, 19],
 * ⁠ [3,   6,  9, 16, 22],
 * ⁠ [10, 13, 14, 17, 24],
 * ⁠ [18, 21, 23, 26, 30]
 * ]
 * 
 * 
 * Given target = 5, return true.
 * 
 * Given target = 20, return false.
 * 
 */

// @lc code=start
class Solution
{
public:
    /*
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int x = matrix.size() - 1;
        int y = 0;
        while (x >= 0 && y < matrix[0].size())
        {
            if (matrix[x][y] == target)
            {
                return true;
            }
            if (matrix[x][y] < target)
            {
                y++;
            }
            else
            {
                x--;
            }
        }
        return false;
    }
    */
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.size() == 0)
            return false;
        int numOfRows = matrix.size();
        int numOfCols = matrix[0].size();
        for (int row = 0; row < numOfRows; row++)
        {
            int left = 0;
            int right = numOfCols;
            while (left < right)
            {
                int mid = left + (right - left) / 2;
                if (matrix[row][mid] == target)
                    return true;
                if (target < matrix[row][mid])
                {
                    right = mid;
                }
                else
                {
                    left = mid + 1;
                }
            }
        }
        return false;
    }
};
// @lc code=end
