/*
合并区间
给出一个区间的集合，请合并所有重叠的区间。

示例 1:

输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2:

输入: [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
*/

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> res;
        if (intervals.empty())
            return res;
        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++)
        {
            vector<int> last = res.back();
            int newLeft = intervals[i][0];
            int newRight = intervals[i][1];
            int lastLeft = last[0];
            int lastRight = last[1];
            vector<int> newPiece;

            if (newLeft > lastRight)
            {
                newPiece.push_back(newLeft);
                newPiece.push_back(newRight);
                res.push_back(newPiece);
            }
            else if (newLeft >= lastLeft && newLeft <= lastRight && newRight > lastRight)
            {
                res.pop_back();
                newPiece.push_back(lastLeft);
                newPiece.push_back(newRight);
                res.push_back(newPiece);
            }
            else if(newLeft >= lastLeft && newLeft <= lastRight && newRight <= lastRight)
            {
                continue;
            }
        }
        return res;
    }
};