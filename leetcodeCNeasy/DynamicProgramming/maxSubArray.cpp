// https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/23/dynamic-programming/56/
/*
 最大子序和
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
进阶:

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
*/

class Solution
{
public:
    /*
    // window slide
    int maxSubArray(vector<int> &nums)
    {
        int res = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            for (int j = i; j < nums.size(); j++)
            {
                sum += nums[j];
                if (sum > res)
                {
                    res = sum;
                }
            }
        }
        return res;
    }
*/
    // dynamic programming
    int maxSubArray(vector<int> &nums)
    {
        // sum[i] means the largest sum array ending at i;
        int sum[nums.size()];
        sum[0] = nums[0];
        int max = sum[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (sum[i - 1] > 0)
            {
                // the previous sub array end results is positive
                // need to add
                sum[i] = sum[i - 1] + nums[i];
            }
            else
            {
                // the previous sub array ending results is negative
                // no need to add
                // start from sum[i]
                // 因为越加越小
                sum[i] = nums[i];
            }
            
            if (sum[i] > max)
            {
                max = sum[i];
            }
        }
        return max;
    }
};