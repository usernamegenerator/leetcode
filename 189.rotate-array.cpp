/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 *
 * https://leetcode.com/problems/rotate-array/description/
 *
 * algorithms
 * Easy (31.61%)
 * Likes:    1791
 * Dislikes: 682
 * Total Accepted:    366.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3,4,5,6,7]\n3'
 *
 * Given an array, rotate the array to the right by k steps, where k is
 * non-negative.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,4,5,6,7] and k = 3
 * Output: [5,6,7,1,2,3,4]
 * Explanation:
 * rotate 1 steps to the right: [7,1,2,3,4,5,6]
 * rotate 2 steps to the right: [6,7,1,2,3,4,5]
 * rotate 3 steps to the right: [5,6,7,1,2,3,4]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-1,-100,3,99] and k = 2
 * Output: [3,99,-1,-100]
 * Explanation: 
 * rotate 1 steps to the right: [99,-1,-100,3]
 * rotate 2 steps to the right: [3,99,-1,-100]
 * 
 * 
 * Note:
 * 
 * 
 * Try to come up as many solutions as you can, there are at least 3 different
 * ways to solve this problem.
 * Could you do it in-place with O(1) extra space?
 * 
 */

// @lc code=start
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int size = nums.size();
        int rotateTimes = size;
        int start = 0;
        int toNextValue = nums[start];
        int nextIdx = (start + k) % size;
        while (rotateTimes)
        {
            // 1. take out value from nextIdx to be replaced
            int temp = nums[nextIdx];
            // 2. replace the value as previously take out
            nums[nextIdx] = toNextValue;
            // 3. if this index is start again,
            // start over from next index
            // recalculate nextIdx
            // reset start to next
            // update the temp value
            if (nextIdx == start)
            {
                nextIdx = (nextIdx + 1) % size;
                start++;
                temp = nums[nextIdx];
            }
            // these two steps are same as 
            // int toNextValue = nums[start];
            // int nextIdx = (start + k) % size;
            // before the while loop
            // update the next value to be replaced
            toNextValue = temp;
            nextIdx = (nextIdx + k) % size;
            rotateTimes--;
        }
    }
};
// @lc code=end

/*
-1. init nextIdx = 0; start = 0

0. nextVal = nums[nextIdx], nextIdx = (nextIdx + k) % size, ; ;
1. take out temp = nums[nextIdx]
2. put nextVal to nextIdx, nums[nextrIdx] = nextVal;
3. set nextVal to new value, nextVal = temp;
4. if nextIdx == start, nextIdx++, start++
*/