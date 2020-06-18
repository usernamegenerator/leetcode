/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 *
 * https://leetcode.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (16.20%)
 * Likes:    1137
 * Dislikes: 5102
 * Total Accepted:    273.2K
 * Total Submissions: 1.7M
 * Testcase Example:  '10\n3'
 *
 * Given two integers dividend and divisor, divide two integers without using
 * multiplication, division and mod operator.
 * 
 * Return the quotient after dividing dividend by divisor.
 * 
 * The integer division should truncate toward zero, which means losing its
 * fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) =
 * -2.
 * 
 * Example 1:
 * 
 * 
 * Input: dividend = 10, divisor = 3
 * Output: 3
 * Explanation: 10/3 = truncate(3.33333..) = 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: dividend = 7, divisor = -3
 * Output: -2
 * Explanation: 7/-3 = truncate(-2.33333..) = -2.
 * 
 * 
 * Note:
 * 
 * 
 * Both dividend and divisor will be 32-bit signed integers.
 * The divisor will never be 0.
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 2^31 − 1 when the
 * division result overflows.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (divisor == 1)
        {
            return dividend;
        }
        if (dividend == 0)
        {
            return 0;
        }
        // corner case
        if (divisor == -1 && dividend == INT_MIN)
        {
            return INT_MAX;
        }
        long long a = dividend;
        long long b = divisor;
        if (a > 0 && b > 0)
        {
            return div(a, b);
        }
        else if (a < 0 && b < 0)
        {
            return div(-a, -b);
        }
        else
        {
            return -div(abs(a), abs(b));
        }
    }
    int div(long long a, long long b)
    {
        if (a < b)
        {
            return 0;
        }
        int count = 1; // count how many b in a, and keep doubling b
        long long tempb = b;
        while (a >= tempb + tempb)
        {
            tempb = tempb + tempb;
            count = count + count;
        }
        return count + div(a - tempb, b);
    }
};
// @lc code=end
