/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (59.58%)
 * Likes:    2869
 * Dislikes: 205
 * Total Accepted:    373.3K
 * Total Submissions: 621K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * Given a non-empty array of integers, return the k most frequent elements.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1], k = 1
 * Output: [1]
 * 
 * 
 * Note: 
 * 
 * 
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is
 * the array's size.
 * It's guaranteed that the answer is unique, in other words the set of the top
 * k frequent elements is unique.
 * You can return the answer in any order.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            if (m.find(nums[i]) != m.end())
            {
                m[nums[i]]++;
            }
            else
            {
                m.insert(make_pair(nums[i], 1));
            }
        }
        priority_queue<pair<int, int>> pq;
        for (unordered_map<int, int>::iterator it = m.begin(); it != m.end(); it++)
        {
            // reverse the pair, so it sorts on the first element (the frequency)
            pq.push(make_pair(it->second, it->first));
        }
        int i = 0;
        vector<int> res;
        while (i < k)
        {
            res.push_back(pq.top().second);
            pq.pop();
            i++;
        }
        return res;
    }
};
// @lc code=end
