/*
 * @lc app=leetcode id=172 lang=cpp
 *
 * [172] Factorial Trailing Zeroes
 *
 * https://leetcode.com/problems/factorial-trailing-zeroes/description/
 *
 * algorithms
 * Easy (37.69%)
 * Likes:    787
 * Dislikes: 1067
 * Total Accepted:    204.6K
 * Total Submissions: 542.3K
 * Testcase Example:  '3'
 *
 * Given an integer n, return the number of trailing zeroes in n!.
 * 
 * Example 1:
 * 
 * 
 * Input: 3
 * Output: 0
 * Explanation: 3! = 6, no trailing zero.
 * 
 * Example 2:
 * 
 * 
 * Input: 5
 * Output: 1
 * Explanation: 5! = 120, one trailing zero.
 * 
 * Note: Your solution should be in logarithmic time complexity.
 * 
 */

// @lc code=start
class Solution
{
public:
    int trailingZeroes(int n)
    {
        int count = 0;
        // ... * (1 * 5) * ... * (1 * 5 * 5) * ... * (2 * 5 * 5) * ... * (3 * 5 * 5) * ... * n
        while (n)
        {
            count += n / 5; // how many 5s
            n = n / 5; // then count how many 25, 50, 75, 125, etc..
        }
        return count;
    }
};
// @lc code=end
