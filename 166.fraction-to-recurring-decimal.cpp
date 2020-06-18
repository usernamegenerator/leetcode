/*
 * @lc app=leetcode id=166 lang=cpp
 *
 * [166] Fraction to Recurring Decimal
 *
 * https://leetcode.com/problems/fraction-to-recurring-decimal/description/
 *
 * algorithms
 * Medium (20.98%)
 * Likes:    819
 * Dislikes: 1773
 * Total Accepted:    121.8K
 * Total Submissions: 571.1K
 * Testcase Example:  '1\n2'
 *
 * Given two integers representing the numerator and denominator of a fraction,
 * return the fraction in string format.
 * 
 * If the fractional part is repeating, enclose the repeating part in
 * parentheses.
 * 
 * Example 1:
 * 
 * 
 * Input: numerator = 1, denominator = 2
 * Output: "0.5"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: numerator = 2, denominator = 1
 * Output: "2"
 * 
 * Example 3:
 * 
 * 
 * Input: numerator = 2, denominator = 3
 * Output: "0.(6)"
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        if (numerator == 0)
            return "0";
        if (denominator == 0)
            return "";
        long long numerator_long = numerator;
        long long denominator_long = denominator;
        string res = "";
        // the result is negative
        if ((numerator_long > 0) ^ (denominator_long > 0))
        {
            res.append("-");
        }
        // convert both to positive
        numerator_long = abs(numerator_long);
        denominator_long = abs(denominator_long);
        // getting the integer part
        res.append(to_string(numerator_long / denominator_long));
        if (numerator_long % denominator_long == 0)
        {
            return res;
        }
        // getting the fraction part
        res.append(".");
        long long remainder = numerator_long % denominator_long; // numerator_long is the remainder
        // use the unordered map to store the occurance of the remainder
        // if the same remainder appears before, meaning it's repeating
        // remainder_occuranceIndex stores
        // the remainder's starting position, if the same remainder occured again
        // then we know where to start the repeat
        unordered_map<long long, int> remainder_occuranceIndex;
        int index = res.size() - 1;
        // if the remainder is not 0
        // and it has not appeared before
        while (remainder && remainder_occuranceIndex.count(remainder) == 0)
        {
            // update the position for the new remainder
            remainder_occuranceIndex[remainder] = ++index;
            remainder *= 10;
            res.append(to_string(remainder / denominator_long));
            remainder = remainder % denominator_long;
        }
        if (remainder_occuranceIndex.count(remainder) == 1)
        {
            res.insert(remainder_occuranceIndex[remainder], "(");
            res.append(")");
        }
        return res;
    }
};
// @lc code=end
