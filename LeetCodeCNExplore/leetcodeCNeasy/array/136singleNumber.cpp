// https://leetcode-cn.com/explore/featured/card/top-interview-questions-easy/1/array/25/
/*
只出现一次的数字
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:

输入: [2,2,1]
输出: 1
示例 2:

输入: [4,1,2,1,2]
输出: 4
*/
#include <vector>
#include <unordered_map>
#include <iostream>
#include <utility>
using namespace std;

class Solution
{
public:
    /*
    // a ^ a = 0
    // a ^ 0 = a
    int singleNumber(vector<int> &nums)
    {
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            res ^= nums[i];
        }
        return res;
    }
    */

    int singleNumber(vector<int> &nums)
    {
        int res;
        // <value,occurance>
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            // not find
            if (m.find(nums[i]) == m.end())
            {
                m.insert(pair<int,int>(nums[i],1));
            }
            else
            {
                m[nums[i]]++;
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (m[nums[i]] == 1)
                res = nums[i];
        }
/*         for (auto x : m)
        {
            cout << x.first <<  " " << x.second << endl;
        }
        cout << endl; */
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> v{2, 2, 1};
    cout << s.singleNumber(v) << endl;
}