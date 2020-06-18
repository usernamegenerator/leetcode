/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (34.12%)
 * Likes:    3860
 * Dislikes: 134
 * Total Accepted:    387.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,5]\n11'
 *
 * You are given coins of different denominations and a total amount of money
 * amount. Write a function to compute the fewest number of coins that you need
 * to make up that amount. If that amount of money cannot be made up by any
 * combination of the coins, return -1.
 * 
 * Example 1:
 * 
 * 
 * Input: coins = [1, 2, 5], amount = 11
 * Output: 3 
 * Explanation: 11 = 5 + 5 + 1
 * 
 * Example 2:
 * 
 * 
 * Input: coins = [2], amount = 3
 * Output: -1
 * 
 * 
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
 * 
 */

// @lc code=start
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, 0xFFFF);
        dp[0] = 0;
        for (int amt = 1; amt < dp.size(); amt++)
        {
            for (int coinIdx = 0; coinIdx < coins.size(); coinIdx++)
            {
                if (coins[coinIdx] > amt)
                    continue;
                // the min of (do not add this coin)and (add this coin)
                // if do not add, then it's just same as before
                // if add, then it's same as without this coin + 1
                dp[amt] = min(dp[amt], dp[amt - coins[coinIdx]] + 1);
            }
        }
        if (dp[amount] == 0xFFFF)
        {
            return -1;
        }
        return dp[amount];
    }
};
// @lc code=end
