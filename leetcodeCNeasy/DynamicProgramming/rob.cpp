// https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/23/dynamic-programming/57/

/*
 打家劫舍
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

示例 1:

输入: [1,2,3,1]
输出: 4
解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。
示例 2:

输入: [2,7,9,3,1]
输出: 12
解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
     偷窃到的最高金额 = 2 + 9 + 1 = 12 。
*/

class Solution
{
public:
     int rob(vector<int> &nums)
     {
          if (nums.empty())
               return 0;
          if (nums.size() == 1)
               return nums[0];
          int f[nums.size()];
          // base case
          f[0] = nums[0];
          f[1] = max(nums[0], nums[1]);
          int maxProfit = max(f[0], f[1]);

          // for each house, there are only two options
          // take the value nums[i], then profit becomes f[n-2] + nums[i]
          // do not take, then profit is same as previous one f[n-1]
          for (int i = 2; i < nums.size(); i++)
          {
               f[i] = max(f[i - 1], f[i - 2] + nums[i]);
               if (f[i] > maxProfit)
                    maxProfit = f[i];
          }
          return maxProfit;
     }
};