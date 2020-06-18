/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 *
 * https://leetcode.com/problems/task-scheduler/description/
 *
 * algorithms
 * Medium (47.81%)
 * Likes:    2981
 * Dislikes: 660
 * Total Accepted:    161.6K
 * Total Submissions: 335K
 * Testcase Example:  '["A","A","A","B","B","B"]\n2'
 *
 * Given a char array representing tasks CPU need to do. It contains capital
 * letters A to Z where different letters represent different tasks. Tasks
 * could be done without original order. Each task could be done in one
 * interval. For each interval, CPU could finish one task or just be idle.
 * 
 * However, there is a non-negative cooling interval n that means between two
 * same tasks, there must be at least n intervals that CPU are doing different
 * tasks or just be idle.
 * 
 * You need to return the least number of intervals the CPU will take to finish
 * all the given tasks.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: tasks = ["A","A","A","B","B","B"], n = 2
 * Output: 8
 * Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of tasks is in the range [1, 10000].
 * The integer n is in the range [0, 100].
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        vector<int> count(26, 0);
        for (int i = 0; i < tasks.size(); i++)
        {
            count[tasks[i] - 'A']++;
        }
        sort(count.begin(), count.end(), greater<int>());
        int total = (count[0] - 1) * (n + 1) + 1;
        for (int i = 1; i < count.size(); i++)
        {
            if (count[i] == count[0])
                total = total + 1;
        }
        return total > tasks.size() ? total : tasks.size();
    }
};
// @lc code=end
