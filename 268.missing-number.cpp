/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 *
 * https://leetcode.com/problems/missing-number/description/
 *
 * algorithms
 * Easy (49.32%)
 * Likes:    1160
 * Dislikes: 1585
 * Total Accepted:    341.2K
 * Total Submissions: 688.1K
 * Testcase Example:  '[3,0,1]'
 *
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
 * find the one that is missing from the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,0,1]
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [9,6,4,2,3,5,7,0,1]
 * Output: 8
 * 
 * 
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant extra space complexity?
 */

// @lc code=start
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int actualSize = nums.size() + 1;
        int sum = (0 + actualSize - 1) * actualSize / 2; // actual sum without missing item
        for (int i = 0; i < nums.size(); i++)
        {
            sum -= nums[i];
        }
        return sum;
    }
};
// @lc code=end
