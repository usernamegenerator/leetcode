/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 *
 * https://leetcode.com/problems/string-to-integer-atoi/description/
 *
 * algorithms
 * Medium (14.81%)
 * Likes:    1165
 * Dislikes: 7198
 * Total Accepted:    441.1K
 * Total Submissions: 3M
 * Testcase Example:  '"42"'
 *
 * Implement atoi which converts a string to an integer.
 * 
 * The function first discards as many whitespace characters as necessary until
 * the first non-whitespace character is found. Then, starting from this
 * character, takes an optional initial plus or minus sign followed by as many
 * numerical digits as possible, and interprets them as a numerical value.
 * 
 * The string can contain additional characters after those that form the
 * integral number, which are ignored and have no effect on the behavior of
 * this function.
 * 
 * If the first sequence of non-whitespace characters in str is not a valid
 * integral number, or if no such sequence exists because either str is empty
 * or it contains only whitespace characters, no conversion is performed.
 * 
 * If no valid conversion could be performed, a zero value is returned.
 * 
 * Note:
 * 
 * 
 * Only the space character ' ' is considered as whitespace character.
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. If the numerical
 * value is out of the range of representable values, INT_MAX (2^31 − 1) or
 * INT_MIN (−2^31) is returned.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "42"
 * Output: 42
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "   -42"
 * Output: -42
 * Explanation: The first non-whitespace character is '-', which is the minus
 * sign.
 * Then take as many numerical digits as possible, which gets 42.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "4193 with words"
 * Output: 4193
 * Explanation: Conversion stops at digit '3' as the next character is not a
 * numerical digit.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "words and 987"
 * Output: 0
 * Explanation: The first non-whitespace character is 'w', which is not a
 * numerical 
 * digit or a +/- sign. Therefore no valid conversion could be performed.
 * 
 * Example 5:
 * 
 * 
 * Input: "-91283472332"
 * Output: -2147483648
 * Explanation: The number "-91283472332" is out of the range of a 32-bit
 * signed integer.
 * Thefore INT_MIN (−2^31) is returned.
 * 
 */
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
// @lc code=start
class Solution
{
public:
    int myAtoi(string str)
    {
        if (str.empty())
        {
            return 0;
        }
        int i = 0;

        // ignore ' '
        while (str[i] == ' ' && i < str.size())
        {
            i++;
        }
        // next should meet '+','-', or digit
        if (str[i] != '+' && str[i] != '-' && !isdigit(str[i]))
        {
            return 0;
        }
        bool isNegative = false;
        string integer = "";
        if (str[i] == '+')
        {
            isNegative = false;
            i++;
            // should meet digit
        }
        else if (str[i] == '-')
        {
            isNegative = true;
            i++;
            // should meet digit
        }
        // meet digit
        while (isdigit(str[i]) && i < str.size())
        {

            integer += str[i];
            i++;
        }

        int p = 0;
        double num = 0;
        for (int j = integer.size() - 1; j >= 0; j--)
        {
            num += (integer[j] - '0') * pow(10, p);
            p++;
        }

        if (isNegative)
        {
            num = 0 - num;
        }

        if (num > INT_MAX)
        {
            return INT_MAX;
        }
        if (num < INT_MIN)
        {
            return INT_MIN;
        }
        return (int)num;
    }
};
// @lc code=end
int main()
{
    string str = ".1";
    Solution s;
    cout << s.myAtoi(str) << endl;
}