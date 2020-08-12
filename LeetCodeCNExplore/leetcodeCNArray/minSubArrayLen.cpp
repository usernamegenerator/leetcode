/*
长度最小的子数组
您已有成功提交记录，请确认是否跳过？

跳过即视为本节
已完成


跳过

重新做题
给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的 连续 子数组，并返回其长度。如果不存在符合条件的子数组，返回 0。

 

示例：

输入：s = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。
 

进阶：

如果你已经完成了 O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/all-about-array/x9gogt/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution
{
public:
    int minSubArrayLen(int s, vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        int i = 0;
        int j = 0;
        int res = INT_MAX;
        int sum = nums[j];
        while (j < nums.size())
        {
            if (sum < s)
            {
                j++;
                if (j < nums.size())
                {
                    sum += nums[j];
                }
            }
            else
            {
                if (j - i + 1 < res)
                {
                    res = j - i + 1;
                }
                sum -= nums[i];
                i++;
            }
        }
        return (res == INT_MAX) ? 0 : res;
    }
};