/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (32.50%)
 * Likes:    755
 * Dislikes: 2192
 * Total Accepted:    437.6K
 * Total Submissions: 1.3M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 * 
 * Note: For the purpose of this problem, we define empty string as valid
 * palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "race a car"
 * Output: false
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    bool isPalindrome(string s)
    {
        if (s.size() == 0)
            return true;

        int i = 0;
        int j = s.size() - 1;
        while (i < j)
        {
            while (!isAlphanumeric(s[i]) && i < j)
            {
                i++;
            }
            while (!isAlphanumeric(s[j]) && i < j)
            {
                j--;
            }
            if (tolower(s[i]) != tolower(s[j]))
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool isAlphanumeric(char c)
    {
        if (!isalpha(c) && !isdigit(c))
            return false;
        return true;
    }
};
// @lc code=end
