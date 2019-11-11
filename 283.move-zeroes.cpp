/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 *
 * https://leetcode.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (55.26%)
 * Likes:    2540
 * Dislikes: 90
 * Total Accepted:    558.7K
 * Total Submissions: 1M
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * Given an array nums, write a function to move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * 
 * Note:
 * 
 * 
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 * 
 */

// @lc code=start
class Solution
{
public:
    /*
    void moveZeroes(vector<int> &nums)
    {
        int i = 0; // i always to the first 0
        while (nums[i] != 0)
        {
            i++;
            if (i == nums.size())
            {
                return;
            }
        }

        int j = i; // j always to the first non-0
        while (nums[j] == 0)
        {
            j++;
            if (j == nums.size())
            {
                return;
            }
        }

        while (1)
        {
            swap(nums[i], nums[j]);
            while (nums[i] != 0)
            {
                i++;
                if (i == nums.size())
                {
                    return;
                }
            }

            j = i; // j always to the first non-0
            while (nums[j] == 0)
            {
                j++;
                if (j == nums.size())
                {
                    return;
                }
            }
        }
        return;
    }
    */
    void moveZeroes(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                int j = i + 1;
                if (j >= nums.size())
                {
                    break;
                }
                else
                {
                    while (nums[j] == 0 && j < nums.size() - 1)
                    {
                        j++;
                    }
                }
                swap(nums[i], nums[j]);
            }
        }
    }
};
// @lc code=end
