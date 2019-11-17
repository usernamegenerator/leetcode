/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 *
 * https://leetcode.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (45.19%)
 * Likes:    2887
 * Dislikes: 98
 * Total Accepted:    510K
 * Total Submissions: 1.1M
 * Testcase Example:  '2'
 *
 * You are climbing a stair case. It takes n steps to reach to the top.
 * 
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 * 
 * Note: Given n will be a positive integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 2
 * Output: 2
 * Explanation: There are two ways to climb to the top.
 * 1. 1 step + 1 step
 * 2. 2 steps
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 3
 * Output: 3
 * Explanation: There are three ways to climb to the top.
 * 1. 1 step + 1 step + 1 step
 * 2. 1 step + 2 steps
 * 3. 2 steps + 1 step
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1 || n == 2 || n == 0)
            return n;
        vector<int> res(n + 1, 0);
        res[0] = 0;
        res[1] = 1;
        res[2] = 2;
        for (int i = 3; i < n + 1; i++)
        {
            res[i] = res[i - 1] + res[i - 2];
        }
        return res[n];
    }
};
// @lc code=end
