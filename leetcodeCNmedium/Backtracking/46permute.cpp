/*
全排列
给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

// https://leetcode-cn.com/problems/permutations/solution/hui-su-suan-fa-xiang-jie-by-labuladong-2/
// 每一个节点（不算根节点）都是一个backtrace call，都要执行一遍for循环

/*

adding 1
adding 2
adding 3
removing 3
removing 2
adding 3
adding 2
removing 2
removing 3
removing 1
adding 2
adding 1
adding 3
removing 3
removing 1
adding 3
adding 1
removing 1
removing 3
removing 2
adding 3
adding 1
adding 2
removing 2
removing 1
adding 2
adding 1
removing 1
removing 2
removing 3
*/
class Solution
{
private:
    vector<vector<int>> res;
    
    void backtrace(vector<int> &current, vector<int> nums)
    {
        if (current.size() == nums.size())
        {
            res.push_back(current);
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (find(current.begin(), current.end(), nums[i]) != current.end())
            {
                continue;
            }

            cout << "adding " << nums[i] << endl;
            current.push_back(nums[i]);
            backtrace(current, nums);
            cout << "removing " << current.back() << endl;
            current.pop_back();
        }
        
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<int> current;
        backtrace(current, nums);
        return res;
    }
};