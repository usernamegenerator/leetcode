/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 *
 * https://leetcode.com/problems/happy-number/description/
 *
 * algorithms
 * Easy (49.91%)
 * Likes:    2045
 * Dislikes: 417
 * Total Accepted:    500.4K
 * Total Submissions: 999K
 * Testcase Example:  '19'
 *
 * Write an algorithm to determine if a number n is "happy".
 * 
 * A happy number is a number defined by the following process: Starting with
 * any positive integer, replace the number by the sum of the squares of its
 * digits, and repeat the process until the number equals 1 (where it will
 * stay), or it loops endlessly in a cycle which does not include 1. Those
 * numbers for which this process ends in 1 are happy numbers.
 * 
 * Return True if n is a happy number, and False if not.
 * 
 * Example: 
 * 
 * 
 * Input: 19
 * Output: true
 * Explanation: 
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 * 
 * 
 */

// @lc code=start
class Solution
{
private:
    unordered_map<int, bool> value_exist;

public:
    bool isHappy(int n)
    {
        if (n == 1)
            return true;
        if (value_exist.find(n) != value_exist.end())
        {
            return false;
        }
        value_exist[n] = true;
        int next = 0;
        while (n)
        {
            int digit = n % 10;
            next += digit * digit;
            n = n / 10;
        }
        return isHappy(next);
    }
};
// @lc code=end
