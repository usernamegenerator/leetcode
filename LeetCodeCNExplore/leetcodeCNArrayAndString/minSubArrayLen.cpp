/*
长度最小的子数组
给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的 连续 子数组，并返回其长度。如果不存在符合条件的子数组，返回 0。

 

示例：

输入：s = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。
 

进阶：

如果你已经完成了 O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int s, vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        int start = 0;
        int end = 0;
        int res = INT_MAX;
        int sum = nums[end];
        while (end < nums.size())
        {
            cout << "sum " << sum << " start " << start << " end " << end << endl;
            if (sum >= s)
            {
                if (end - start + 1 < res)
                {
                    res = end - start + 1;
                }
                sum -= nums[start];
                start++;
            }
            else
            {
                end++;
                if (end < nums.size())
                {
                    sum += nums[end];
                }
            }
        }
        return (res == INT_MAX) ? 0 : res;
    }
};

int main()
{
    //int s = 15;
    //vector<int> a = {5, 1, 3, 5, 10, 7, 4, 9, 2, 8};
    int s = 3;
    vector<int> a = {1, 1};
    Solution solution;
    cout << "res = " << solution.minSubArrayLen(s, a) << endl;
}