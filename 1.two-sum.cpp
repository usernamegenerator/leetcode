/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
#include <vector>
#include <map>

using namespace std;
// @lc code=start

class Solution
{
public:
    /*
brute force solution:
iterate the array from the first index
    iterate the array from next index
        check if they add up to the targe
*/
    /*
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
*/
    // use hashmap look up solution:
    /*
iterate through the array, push the elements to map, <key,value> = <element, index>
iterate through the array again, take target-element, and look up in the map
if found, return results
*/
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> m;
        vector<int> res;
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
        {
            m.insert(pair<int, int>(*it, it - nums.begin()));
        }
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
        {
            int remain = target - *it;
            map<int, int>::iterator ij = m.find(remain);
            // make sure it doesn't count itself
            // e.g. [3,2,4] 6, will not return [0,0] which is 3+3
            if (ij != m.end() && (ij->second != it-nums.begin()))
            {
                res.push_back(it - nums.begin());
                res.push_back(ij->second);
                return res;
            }
        }
        return res;
    }
};

// @lc code=end
