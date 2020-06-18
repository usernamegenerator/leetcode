/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (34.06%)
 * Likes:    3412
 * Dislikes: 167
 * Total Accepted:    447.7K
 * Total Submissions: 1.3M
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 * 
 * Example:
 * 
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * board and word consists only of lowercase and uppercase English letters.
 * 1 <= board.length <= 200
 * 1 <= board[i].length <= 200
 * 1 <= word.length <= 10^3
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (dfs(i, j, "", board, word, visited, 0))
                    return true;
            }
        }
        return false;
    }
    bool dfs(int x, int y, string current, vector<vector<char>> &board, string word, vector<vector<bool>> &visited, int index)
    {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size())
        {
            return false;
        }
        if (visited[x][y])
        {
            return false;
        }
        if (word[index] != board[x][y])
        {
            return false;
        }
        if (index == word.size() - 1)
        {
            return true;
        }
        current += (board[x][y]);
        visited[x][y] = true;
        if (
            dfs(x - 1, y, current, board, word, visited, index + 1) ||
            dfs(x +1, y, current, board, word, visited, index + 1) ||
            dfs(x, y - 1, current, board, word, visited, index + 1) ||
            dfs(x, y + 1, current, board, word, visited, index + 1))
        {
            return true;
        }
        current.pop_back();
        visited[x][y] = false;
        return false;
    }
};
// @lc code=end
