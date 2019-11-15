/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (41.89%)
 * Likes:    944
 * Dislikes: 7553
 * Total Accepted:    329.5K
 * Total Submissions: 780.7K
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is the sequence of integers with the first five
 * terms as following:
 * 
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * Given an integer n where 1 ≤ n ≤ 30, generate the n^th term of the
 * count-and-say sequence.
 * 
 * Note: Each term of the sequence of integers will be represented as a
 * string.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: "1"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 4
 * Output: "1211"
 * 
 */

// @lc code=start
#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";
        if (n == 2)
            return "11";

        string pre = countAndSay(n - 1);
        cout << pre << endl;
        int count = 1;
        char pattern = pre[0];
        string res;
        for (int i = 1; i < pre.size(); i++)
        {
            if (pre[i] == pattern)
            {
                count++;
            }
            else
            {
                // pattern changed
                res += (char)(count + '0');
                res += pattern;
                pattern = pre[i];
                count = 1;
            }
        }
        res += (char)(count + '0');
        res += pattern;

        return res;
    }
};
// @lc code=end

int main()
{
    Solution s;
    cout << s.countAndSay(5) << endl;
}
