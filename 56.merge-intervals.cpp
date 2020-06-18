/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (38.32%)
 * Likes:    3966
 * Dislikes: 280
 * Total Accepted:    577.1K
 * Total Submissions: 1.5M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * 
 * NOTE: input types have been changed on April 15, 2019. Please reset to
 * default code definition to get new method signature.
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> res;
        if (intervals.size() == 0)
        {
            return res;
        }
        
        sort(intervals.begin(), intervals.end());

        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++)
        {
            vector<int> previous = res.back();
            int thisLeft = intervals[i][0];
            int thisRight = intervals[i][1];
            int previousLeft = previous[0];
            int previousRight = previous[1];
            /*
            |<---->|
                |<---->|
            */
            // merge
            if (previousLeft <= thisLeft && thisLeft <= previousRight && previousRight <= thisRight)
            {
                res.pop_back();
                res.push_back({previousLeft, thisRight});
            }
            /*
            |<---------->|
               |<---->|
            */
            // no merge, just keep previous and skip this one
            if (previousLeft <= thisLeft && thisLeft <= previousRight && thisRight <= previousRight)
            {
                continue;
            }
            /*
            |<---->|
                        |<---->|
            */
            // no merge, just add this one
            if (previousRight < thisLeft)
            {
                res.push_back({thisLeft, thisRight});
            }
        }
        return res;
    }
};
// @lc code=end
