/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (61.27%)
 * Likes:    3631
 * Dislikes: 103
 * Total Accepted:    582.6K
 * Total Submissions: 935.5K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution
{
private:
    vector<vector<int>> res;
    void backtrace(vector<int> &current, vector<int> &nums)
    {
        if (current.size() == nums.size())
        {
            res.push_back(current);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (find(current.begin(), current.end(), nums[i]) != current.end())
            {
                continue;
            }
            current.push_back(nums[i]);
            backtrace(current, nums);
            current.pop_back();
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<int> current;
        backtrace(current, nums);
        return res;
    }
};
// @lc code=end
