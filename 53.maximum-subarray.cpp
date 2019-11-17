/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (44.69%)
 * Likes:    5506
 * Dislikes: 234
 * Total Accepted:    688.4K
 * Total Submissions: 1.5M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 * 
 * Example:
 * 
 * 
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 * 
 */

// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        vector<int> res(nums.size(), 0);
        res[0] = nums[0];
        int max = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] + res[i - 1] > nums[i])
            {
                res[i] = nums[i] + res[i - 1];
            }
            else
            {
                res[i] = nums[i];
            }
            if (res[i] > max)
            {
                max = res[i];
            }
        }
        return max;
    }
};
// @lc code=end
