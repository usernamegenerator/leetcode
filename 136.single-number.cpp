/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 *
 * https://leetcode.com/problems/single-number/description/
 *
 * algorithms
 * Easy (61.58%)
 * Likes:    3015
 * Dislikes: 117
 * Total Accepted:    562.5K
 * Total Submissions: 907.9K
 * Testcase Example:  '[2,2,1]'
 *
 * Given a non-empty array of integers, every element appears twice except for
 * one. Find that single one.
 * 
 * Note:
 * 
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 * 
 * Example 1:
 * 
 * 
 * Input: [2,2,1]
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,1,2,1,2]
 * Output: 4
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    /*
    // a ^ a = 0;
    // a ^ 0 = a
    int singleNumber(vector<int> &nums)
    {    
        int x_or = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            x_or ^= nums[i];
        }
        return x_or;
    }
*/

    int singleNumber(vector<int> &nums)
    {
        // <num,times>
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            if (m.find(nums[i]) == m.end())
            {
                m.insert(pair<int, int>(nums[i], 1));
            }
            else
            {
                m[nums[i]]++;
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (m[nums[i]] == 1)
            {
                return nums[i];
            }
        }
        return -1;
    }
};
// @lc code=end
