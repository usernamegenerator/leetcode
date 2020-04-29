/*
单词搜索
给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

 

示例:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

给定 word = "ABCCED", 返回 true
给定 word = "SEE", 返回 true
给定 word = "ABCB", 返回 false
 

提示：

board 和 word 中只包含大写和小写英文字母。
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3
*/

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        vector<vector<bool>> marked(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (backtrace(board, i, j, word, 0, "", marked))
                    return true;
            }
        }
        return false;
    }
    bool backtrace(vector<vector<char>> &board, int i, int j, string word, int wordIndex, string current, vector<vector<bool>> &marked)
    {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
        {
            return false;
        }
        if (marked[i][j] == true)
        {
            return false;
        }
        if (word[wordIndex] != board[i][j])
        {
            return false;
        }
        if (wordIndex == word.size() - 1)
        {
            return true;
        }
        marked[i][j] = true;
        current = current + board[i][j];
        if (backtrace(board, i - 1, j, word, wordIndex + 1, current, marked) ||
            backtrace(board, i + 1, j, word, wordIndex + 1, current, marked) ||
            backtrace(board, i, j - 1, word, wordIndex + 1, current, marked) ||
            backtrace(board, i, j + 1, word, wordIndex + 1, current, marked))
        {
            return true;
        }
        marked[i][j] = false;
        current.pop_back();
        return false;
    }
};