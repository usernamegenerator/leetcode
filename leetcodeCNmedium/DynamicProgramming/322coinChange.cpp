/*
零钱兑换
给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

 

示例 1:

输入: coins = [1, 2, 5], amount = 11
输出: 3 
解释: 11 = 5 + 5 + 1
示例 2:

输入: coins = [2], amount = 3
输出: -1
 

说明:
你可以认为每种硬币的数量是无限的。
*/

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1); // don't count 0
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            dp[i] = 0xFFFF;
        }
        for (int amt = 1; amt <= amount; amt++)
        {
            for (int coin = 0; coin < coins.size(); coin++)
            {
                // if coin greater than the amt, then there is no way to make it
                if (amt >= coins[coin])
                {
                    dp[amt] = min(dp[amt], dp[amt - coins[coin]] + 1); // add 1 is to add 1 more coin
                }
            }
        }
        if (dp[amount] == 0xFFFF)
        {
            return -1;
        }
        else
        {
            return dp[amount];
        }
    }
};