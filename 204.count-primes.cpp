/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (29.90%)
 * Likes:    1378
 * Dislikes: 464
 * Total Accepted:    283.9K
 * Total Submissions: 941.6K
 * Testcase Example:  '10'
 *
 * Count the number of prime numbers less than a non-negative number, n.
 * 
 * Example:
 * 
 * 
 * Input: 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int countPrimes(int n)
    {
        if (n == 0 || n == 1)
            return 0;
        vector<bool> prime(n, true);
        prime[0] = false;
        prime[1] = false;
        prime[2] = true;
        for (int i = 2; i < n; i++)
        {
            if (prime[i] == true)
            {
                int j = 1;
                while (i + i * j < n)
                {
                    prime[i + i * j] = false;
                    j++;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (prime[i])
            {
                //cout << i << " ";
                count++;
            }
        }
        //cout << endl;
        return count;
    }
};
// @lc code=end
