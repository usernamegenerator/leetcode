/*
 三数之和
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        // 1.sort
        sort(nums.begin(), nums.end());

        // iterate through the array as the index
        for (int idx = 0; idx < nums.size() - 2; idx++)
        {
            // find the first non-duplicated fixed number
            if (idx > 0 && nums[idx - 1] == nums[idx])
            {
                continue;
            }

            int target = 0 - nums[idx];
            // take two more indexes,
            // one from the idx + 1
            // one from the nums.size() - 1
            int i = idx + 1;
            int j = nums.size() - 1;
            while (i < nums.size() && i < j)
            {
                // check results, if find
                if (nums[i] + nums[j] == target)
                {
                    res.push_back({nums[idx], nums[i], nums[j]});
                    // remove i's duplicate
                    while (i < j && nums[i + 1] == nums[i])
                        i++;
                    // remove j's duplicate
                    while (i < j && nums[j - 1] == nums[j])
                        j--;
                    i++;
                    j--;
                }
                // not find
                else
                {
                    if (nums[i] + nums[j] < target)
                    {
                        i++;
                    }
                    else
                    {
                        j--;
                    }
                }
            }
        }

        return res;
    }
};

int main()
{
    //vector<int> nums{-1, 0, 1, 2, -1, -4};
    vector<int> nums{0, 0, 0, 0};
    Solution s;
    vector<vector<int>> res;
    res = s.threeSum(nums);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}