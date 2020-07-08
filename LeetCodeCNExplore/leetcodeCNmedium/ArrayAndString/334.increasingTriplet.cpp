/*
递增的三元子序列
给定一个未排序的数组，判断这个数组中是否存在长度为 3 的递增子序列。

数学表达式如下:

如果存在这样的 i, j, k,  且满足 0 ≤ i < j < k ≤ n-1，
使得 arr[i] < arr[j] < arr[k] ，返回 true ; 否则返回 false 。
说明: 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1) 。

示例 1:

输入: [1,2,3,4,5]
输出: true
示例 2:

输入: [5,4,3,2,1]
输出: false
*/
#include <vector>
#include <climits>
#include <iostream>
using namespace std;

// idea is to find the first minimum number,
// then find the second minimum number, which has to be greater than the minimum number
// then iterater through the left, if find an element that is greater than the second minimum, return true;
class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        if (nums.size() < 3)
            return false;

        int firstMin = INT_MAX;
        int secondMin = INT_MAX;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] <= firstMin)
            {
                firstMin = nums[i];
            }
            else if (firstMin != INT_MAX && nums[i] <= secondMin && nums[i] > firstMin)
            {
                secondMin = nums[i];
            }
            else if (nums[i] > secondMin)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    //vector<int> v{5,0,4,1,3,2};
    vector<int> v{5,4,3,2,1};
    cout << s.increasingTriplet(v) << endl;
    return 0;
}