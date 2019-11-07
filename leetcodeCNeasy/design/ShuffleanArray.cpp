// https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/24/design/58/

/*
Shuffle an Array
打乱一个没有重复元素的数组。

示例:

// 以数字集合 1, 2 和 3 初始化数组。
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// 打乱数组 [1,2,3] 并返回结果。任何 [1,2,3]的排列返回的概率应该相同。
solution.shuffle();

// 重设数组到它的初始状态[1,2,3]。
solution.reset();

// 随机返回数组[1,2,3]打乱后的结果。
solution.shuffle();
*/
#include <vector>
#include <cstdlib>
using namespace std;
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
            swap(shuffled[i], shuffled[j]);
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

int main()
{
    vector<int> nums = {1, 2, 3};
    Solution *obj = new Solution(nums);
    vector<int> param_1 = obj->reset();
    vector<int> param_2 = obj->shuffle();
}