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

class Solution
{
public:
    // https://www.youtube.com/watch?v=LPFhl65R7ww&t=1013s
    // https://blog.csdn.net/chen_xinjia/article/details/69258706
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        // find which array is smaller
        int size1 = nums1.size();
        int size2 = nums2.size();
        if (size1 > size2)
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        // if it's odd number, the partition will have one more element on the left
        // median = max(nums1_left_max, nums2_left_max)
        // if it's even number, two partitions have the same number of elements
        // median = ( max(nums1_left_max, nums2_left_max) + min(nums1_right_min,nums2_right_min) ) / 2
        bool isOddNumber = (size1 + size2) % 2;
        int low = 0;
        int high = size1;
        
        while (low <= high)
        {
            // partition1 + partition2 = (size1 + size2 + 1) / 2;
            int parition1 = low + (high - low) / 2;
            int parition2 = (size1 + size2 + 1) / 2 - parition1;
            int nums1_left_max = (parition1 == 0) ? INT_MIN : nums1[parition1 - 1];
            int nums2_left_max = (parition2 == 0) ? INT_MIN : nums2[parition2 - 1];
            int nums1_right_min = (parition1 == size1) ? INT_MAX : nums1[parition1];
            int nums2_right_min = (parition2 == size2) ? INT_MAX : nums2[parition2];


            if (nums1_left_max <= nums2_right_min && nums2_left_max <= nums1_right_min)
            {
                if (isOddNumber)
                {
                    return (double)max(nums1_left_max, nums2_left_max);
                }
                else
                {
                    return (double)(max(nums1_left_max, nums2_left_max) + min(nums1_right_min, nums2_right_min)) / 2.0;
                }
            }

            // parition need to move to left
            else if (nums1_left_max > nums2_right_min)
            {
                high = parition1 - 1;
            }
            else // nums2_left_max > nums1_right_min // move to right
            {
                low = parition1 + 1;
            }
        }
        return 0.0;
    }

    // merge two sorted array into one
    // median = (arr[size/2] + arr[size/2-1]) / 2 // even number
    // median = arr[size/2];
    // this is O(M+N)
    // doesn't meet O(log(M+N))
    // bus still passes the OJ
    // 2085/2085 cases passed (20 ms)
    // Your runtime beats 69.77 % of cpp submissions
    // Your memory usage beats 16.5 % of cpp submissions (10.6 MB)
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
