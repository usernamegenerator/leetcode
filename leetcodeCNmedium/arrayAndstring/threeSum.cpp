// https://leetcode-cn.com/explore/interview/card/top-interview-questions-medium/29/array-and-strings/75/

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
#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        // 1. sort the array to deal with the duplicates
        sort(nums.begin(), nums.end());
        // 2. fix a number i;
        int size = nums.size();
        for (int i = 0; i < size - 2; i++)
        {

            // find the first non-duplicated fixed number
            if (i > 0 && nums[i - 1] == nums[i])
            {
                continue;
            }

            // sum to find;
            int sum = 0 - nums[i];
            //3. scanning the rest of the array
            // 1st index from i+1;
            // 2nd index from size-1;
            int low = i + 1;
            int high = size - 1;
            while (low < high)
            {
                // if find
                if (nums[low] + nums[high] == sum)
                {
                    vector<int> v{nums[i], nums[low], nums[high]};
                    res.push_back(v);
                    // remove duplicate from low
                    while (low < high && nums[low] == nums[low + 1])
                    {
                        low++;
                    }
                    // remove duplicate from high
                    while (low < high && nums[high] == nums[high - 1])
                    {
                        high--;
                    }

                    low++;
                    high--;
                }
                // if not find
                else if (nums[low] + nums[high] < sum)
                {
                    low++;
                }
                else
                {
                    high--;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> v{-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = s.threeSum(v);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}