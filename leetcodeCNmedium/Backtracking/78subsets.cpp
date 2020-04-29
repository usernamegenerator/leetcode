/*
子集
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

// https://leetcode-cn.com/problems/subsets/solution/er-jin-zhi-wei-zhu-ge-mei-ju-dfssan-chong-si-lu-9c/
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    vector<vector<int>> res;

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        if (nums.size() == 0)
            return res;
        vector<int> current;
        int index = 0;
        backtrace(index, current, nums);
        return res;
    }
    void backtrace(int index, vector<int> current, vector<int> nums)
    {
        /*
        cout << "backtrace cur ";
        for (int k = 0; k < current.size(); k++)
        {
            cout << "["<< current[k] << "]";
        }
        cout << " index " << index << endl;
        */

        res.push_back(current);
        for (int i = index; i < nums.size(); i++)
        {
            current.push_back(nums[i]);
            /*
            cout << "for i " << i << " cur ";
            for (int k = 0; k < current.size(); k++)
            {
                cout << current[k] << " ";
            }
            cout << endl;
            */
            backtrace(i + 1, current, nums);

            //cout << "back i " << i << " index " << index << endl;

            current.pop_back();
        }
    }
};

int main()
{
    vector<int> test{1, 2, 3};
    Solution s;
    s.subsets(test);
}