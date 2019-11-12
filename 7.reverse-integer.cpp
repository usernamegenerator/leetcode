/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (25.50%)
 * Likes:    2580
 * Dislikes: 4042
 * Total Accepted:    859.7K
 * Total Submissions: 3.4M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 123
 * Output: 321
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -123
 * Output: -321
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 120
 * Output: 21
 * 
 * 
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 0 when the reversed
 * integer overflows.
 * 
 */

// @lc code=start
class Solution
{
public:
    int reverse(int x)
    {
        vector<int> r;
        int tempX = x;

        while (tempX)
        {
            r.push_back(tempX % 10);
            tempX = tempX / 10;
        }

        int numOfDigit = 0;
        double sum = 0;
        for (int i = r.size() - 1; i >= 0; i--)
        {
            double tempSum = r[i] * pow(10, numOfDigit);
            sum += tempSum;
            numOfDigit++;
        }

        if (sum > pow(2, 31) - 1 || sum < 0 - pow(2, 31))
            return 0;

        return (int)sum;
    }
};
// @lc code=end
