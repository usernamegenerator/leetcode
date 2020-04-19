/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (25.94%)
 * Likes:    6083
 * Dislikes: 736
 * Total Accepted:    830.6K
 * Total Submissions: 3.2M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ret;
        if (nums.size() < 3)
            return ret;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            // to remove duplicate of i
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> res{nums[i], nums[j], nums[k]};
                    ret.push_back(res);
                    
                    // remove duplicate of j and k
                    while (j < k && nums[j] == nums[j + 1])
                    {
                        j++;
                    }
                    while (j < k && nums[k] == nums[k - 1])
                    {
                        k--;
                    }
                    // continue to search under this i
                    j++;
                    k--;

                }
                else
                {
                    if (nums[i] + nums[j] + nums[k] < 0)
                    {
                        j++;
                    }
                    else if (nums[i] + nums[j] + nums[k] > 0)
                    {
                        k--;
                    }
                }
            }
        }
        return ret;
    }
};
// @lc code=end
