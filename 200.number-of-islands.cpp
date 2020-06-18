/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (45.67%)
 * Likes:    5192
 * Dislikes: 192
 * Total Accepted:    693.3K
 * Total Submissions: 1.5M
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 * 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 * 
 * Output: 3
 * 
 */

// @lc code=start
class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.size() == 0)
        {
            return 0;
        }
        int numOfRows = grid.size();
        int numOfCols = grid[0].size();
        vector<vector<bool>> visited(numOfRows, vector<bool>(numOfCols, false));
        int count = 0;
        for (int i = 0; i < numOfRows; i++)
        {
            for (int j = 0; j < numOfCols; j++)
            {
                if (grid[i][j] == '1' && visited[i][j] == false)
                {
                    count++;
                    dfs(i, j, grid, visited);
                }
            }
        }
        return count;
    }
    void dfs(int row, int col, vector<vector<char>> &grid, vector<vector<bool>> &visited)
    {
        if (visited[row][col] || grid[row][col]=='0')
            return;
        visited[row][col] = true;
        if (row > 0)
        {
            dfs(row - 1, col, grid, visited);
        }
        if (row < grid.size() - 1)
        {
            dfs(row + 1, col, grid, visited);
        }
        if (col > 0)
        {
            dfs(row, col - 1, grid, visited);
        }
        if (col < grid[0].size() - 1)
        {
            dfs(row, col + 1, grid, visited);
        }
    }
};
// @lc code=end
