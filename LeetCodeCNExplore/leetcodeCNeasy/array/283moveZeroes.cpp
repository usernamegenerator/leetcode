// https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/1/array/28/

/*
移动零
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

示例:

输入: [0,1,0,3,12]
输出: [1,3,12,0,0]
说明:

必须在原数组上操作，不能拷贝额外的数组。
尽量减少操作次数。
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    // i to the 1st 0
    // j to the 1st non-0
    // swap i and j
    // O(N^2)
    void moveZeroes(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                int j = i + 1;
                if (j == nums.size())
                    break;
                while (nums[j] == 0 && j < nums.size() - 1)
                {
                    j++;
                }
                swap(nums[i], nums[j]);
            }
        }
    }
};

int main()
{
    Solution s;
    // vector<int> v{0, 1, 0, 3, 12};
    vector<int> v{0, 0, 1};
    s.moveZeroes(v);
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}