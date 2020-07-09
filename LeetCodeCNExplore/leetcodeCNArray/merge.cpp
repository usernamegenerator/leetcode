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
#include <iostream>
#include <vector>
using namespace std;

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
            vector<int> pre = res.back();
            int pre_left = pre[0];
            int pre_right = pre[1];
            int this_left = intervals[i][0];
            int this_right = intervals[i][1];
            if (pre_left <= this_left && this_left <= pre_right && pre_right <= this_right)
            {
                // _____
                //    _____
                // update previous right boundary to this right boundary
                res.pop_back();
                res.push_back(vector<int>{pre_left, this_right});
            }
            else if (pre_right <= this_left)
            {
                // ______
                //          ___________
                res.push_back(vector<int>{this_left, this_right});
            }
            else // if(pre_left <= this_left && this_right <= pre_right)
            {
                // ____________
                //    _______
                continue;
            }
        }
        return res;
    }
};