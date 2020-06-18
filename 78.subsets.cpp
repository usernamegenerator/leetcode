/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (58.86%)
 * Likes:    3443
 * Dislikes: 79
 * Total Accepted:    540.5K
 * Total Submissions: 902.9K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start

// https://www.cnblogs.com/TenosDoIt/p/3451902.html
class Solution
{
private:
    vector<vector<int>> res;

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> current;
        int index = 0;
        dfs(index, current, nums);
        return res;
    }
    void dfs(int index, vector<int> current, vector<int> &nums)
    {
        if (index == nums.size())
        {
            res.push_back(current);
            return;
        }
        // take this index
        current.push_back(nums[index]);
        dfs(index + 1, current, nums);
        current.pop_back();
        // do not take this index
        dfs(index + 1, current, nums);
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> input{1, 2, 3};
    s.subsets(input);
}
