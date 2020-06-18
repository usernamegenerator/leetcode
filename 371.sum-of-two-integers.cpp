/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 *
 * https://leetcode.com/problems/sum-of-two-integers/description/
 *
 * algorithms
 * Easy (50.63%)
 * Likes:    1185
 * Dislikes: 2138
 * Total Accepted:    183.7K
 * Total Submissions: 362.5K
 * Testcase Example:  '1\n2'
 *
 * Calculate the sum of two integers a and b, but you are not allowed to use
 * the operator + and -.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: a = 1, b = 2
 * Output: 3
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: a = -2, b = 3
 * Output: 1
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int getSum(int a, int b)
    {
        int lower = 0;
        unsigned int carry = 0;
        while (1)
        {
            lower = a ^ b;
            carry = (unsigned int)(a & b);
            if (carry == 0)
            {
                break;
            }
            a = lower;
            b = carry << 1;
        }
        return lower;
    }
};
// @lc code=end
