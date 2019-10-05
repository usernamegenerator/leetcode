/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (27.41%)
 * Likes:    5115
 * Dislikes: 737
 * Total Accepted:    516.1K
 * Total Submissions: 1.9M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 * 
 * You may assume nums1 and nums2 cannot be both empty.
 * 
 * Example 1:
 * 
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * 
 * Example 2:
 * 
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * 
 */
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
// @lc code=start
// https://www.youtube.com/watch?v=LPFhl65R7ww&t=1013s
class Solution
{
public:
    // merge two sorted array into one
    // median = (arr[size/2] + arr[size/2-1]) / 2 // even number
    // median = arr[size/2];
    /*
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> merge;
        int i = 0;
        int j = 0;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] < nums2[j])
            {
                merge.push_back(nums1[i]);
                i++;
            }
            else
            {
                merge.push_back(nums2[j]);
                j++;
            }
        }

        while (i < nums1.size())
        {
            merge.push_back(nums1[i]);
            i++;
        }
        while (j < nums2.size())
        {
            merge.push_back(nums2[j]);
            j++;
        }

        int size = merge.size();
        if (size % 2 == 0)
        {
            return (merge[size / 2] + merge[size / 2 - 1]) / 2.0;
        }
        else
        {
            return (merge[size / 2]) / 1.0;
        }
    }
    */
};
// @lc code=end
