// https://leetcode-cn.com/explore/featured/card/top-interview-questions-easy/1/array/26/
/*
两个数组的交集 II
给定两个数组，编写一个函数来计算它们的交集。

示例 1:

输入: nums1 = [1,2,2,1], nums2 = [2,2]
输出: [2,2]
示例 2:

输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出: [4,9]
说明：

输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。
我们可以不考虑输出结果的顺序。
进阶:

如果给定的数组已经排好序呢？你将如何优化你的算法？
如果 nums1 的大小比 nums2 小很多，哪种方法更优？
如果 nums2 的元素存储在磁盘上，磁盘内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？
*/

#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    /*
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() < nums2.size())
            intersect(nums2, nums1);

        // <value,occurance>
        unordered_map<int, int> m;
        vector<int> res;
        // 1. iterate through the one with bigger size, increment the <value,occurance> to map
        for (int i = 0; i < nums1.size(); i++)
        {
            // not find
            if (m.find(nums1[i]) == m.end())
            {
                m[nums1[i]] = 1;
            }
            else
            {
                m[nums1[i]]++;
            }
        }

        // 2. iterate through the one with smaller size, add to res, decrement the <value,occurance> to map
        for (int i = 0; i < nums2.size(); i++)
        {
            // find, decrement
            if (m.find(nums2[i]) != m.end())
            {
                if (m[nums2[i]] != 0)
                {
                    res.push_back(nums2[i]);
                    m[nums2[i]]--;
                }
            }
        }
        return res;
    }
*/
    // sort two array, index through,
    // if same, add to res
    // if not same, increase the index on the array with the smaller element
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0;
        int j = 0;
        vector<int> res;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i]==nums2[j])
            {
                res.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i] < nums2[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    // vector<int> nums1 = {1,2,2,1};
    vector<int> nums1 = {4, 9, 5};
    // vector<int> nums2 = {2,2};
    vector<int> nums2 = {9, 4, 9, 8, 4};
    vector<int> res = s.intersect(nums1, nums2);
    for (auto x : res)
    {
        cout << x << " ";
    }
    cout << endl;
}
