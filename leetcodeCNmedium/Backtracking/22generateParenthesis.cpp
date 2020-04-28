/*
括号生成
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

 

示例：

输入：n = 3
输出：[
       "((()))",
       "(()())",
       "(())()",
       "()(())",
       "()()()"
     ]
*/


/*
for n = 2

(
((
(()
(())
()
()(
()()

*/
class Solution
{
private:
    vector<string> res;
    void dfs(int left, int right, string str)
    {
        cout << str << endl;
        if (left == 0 && right == 0)
        {
            res.push_back(str);
            return;
        }
        if (left > 0)
        {
            dfs(left - 1, right, str + "(");
        }
        if (right > left)
        {
            dfs(left, right - 1, str + ")");
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        dfs(n, n, "");
        return res;
    }
};