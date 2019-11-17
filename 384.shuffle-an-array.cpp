/*
 * @lc app=leetcode id=384 lang=cpp
 *
 * [384] Shuffle an Array
 *
 * https://leetcode.com/problems/shuffle-an-array/description/
 *
 * algorithms
 * Medium (50.92%)
 * Likes:    350
 * Dislikes: 800
 * Total Accepted:    95.4K
 * Total Submissions: 186.2K
 * Testcase Example:  '["Solution","shuffle","reset","shuffle"]\n[[[1,2,3]],[],[],[]]'
 *
 * Shuffle a set of numbers without duplicates.
 * 
 * 
 * Example:
 * 
 * // Init an array with set 1, 2, and 3.
 * int[] nums = {1,2,3};
 * Solution solution = new Solution(nums);
 * 
 * // Shuffle the array [1,2,3] and return its result. Any permutation of
 * [1,2,3] must equally likely to be returned.
 * solution.shuffle();
 * 
 * // Resets the array back to its original configuration [1,2,3].
 * solution.reset();
 * 
 * // Returns the random shuffling of array [1,2,3].
 * solution.shuffle();
 * 
 * 
 */

// @lc code=start
class Solution
{
private:
    vector<int> original;
    vector<int> shuffled;

public:
    Solution(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            original.push_back(nums[i]);
            shuffled.push_back(nums[i]);
        }
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
        return original;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
        int size = shuffled.size();
        for (int i = 0; i < size; i++)
        {
            int j = rand() % size;
            swap(shuffled[i],shuffled[j]);
        }
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end
