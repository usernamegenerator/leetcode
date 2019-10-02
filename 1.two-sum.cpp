/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
#include <vector>
using namespace std;
// @lc code=start
/*
brute force solution:
iterate the array from the first index
    iterate the array from next index
        check if they add up to the targe
*/
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> res;
        bool resFound = false;
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
        {
            if(resFound)
                break;
            for (vector<int>::iterator ij = it + 1; ij != nums.end(); ij++)
            {
                if (*it + *ij == target)
                {
                    res.push_back(it - nums.begin());
                    res.push_back(ij - nums.begin());
                    resFound = true;
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end
