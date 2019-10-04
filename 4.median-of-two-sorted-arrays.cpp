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
// 1st trial: 
// use merge sort like algorithm, keep "merge" two arrays together until find the targetIndex
// failed...
/*
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int totalSize = nums1.size() + nums2.size();
        int targetIndex = 0;
        
        bool isNeedTwoIndex = false;
        if (totalSize % 2 == 0)
        {
            isNeedTwoIndex = true;
            targetIndex = totalSize / 2 - 1;
            // median is ([index] + [index + 1]) / 2
        }
        else
        {
            isNeedTwoIndex = false;
            targetIndex = totalSize / 2;
            // median is ([index]) / 2
        }

        int i = 0;
        int j = 0;
        int index = 0;
        float median = 0;

        cout << targetIndex << " " << isNeedTwoIndex << endl;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] < nums2[j])
            {
                i++;
                index++;
                if (index == targetIndex)
                {
                    if (!isNeedTwoIndex)
                    {
                        median = nums1[i];
                        break;
                    }
                    else
                    {
                        if (i + 1 < nums1.size())
                        {
                            int mini = min(nums2[j], nums1[i + 1]);
                            median = (nums1[i] + mini) / 2.0;
                            break;
                        }
                        else
                        {
                            median = (nums1[i] + nums2[j]) / 2.0;
                            break;
                        }
                    }
                }
            }
            else
            {
                j++;
                index++;
                if (index == targetIndex)
                {
                    if (!isNeedTwoIndex)
                    {
                        median = nums2[j];
                        break;
                    }
                    else
                    {
                        if (j + 1 < nums2.size())
                        {
                            int mini = min(nums1[i], nums2[j + 1]);
                            median = (nums2[j] + mini) / 2.0;
                            break;
                        }
                        else
                        {
                            median = (nums2[j] + nums1[i]) / 2.0;
                            break;
                        }
                    }
                }
            }
        }
        if (index < targetIndex)
        {
            while (i < nums1.size())
            {
                i++;
                index++;
                if (index == targetIndex)
                {
                    if (!isNeedTwoIndex)
                    {
                        median = nums1[i];
                        break;
                    }
                    else
                    {
                        median = (nums1[i] + nums1[i + 1]) / 2.0;
                        break;
                    }
                }
            }

            while (j < nums2.size())
            {
                j++;
                index++;
                if (index == targetIndex)
                {
                    if (!isNeedTwoIndex)
                    {
                        median = nums2[j];
                        break;
                    }
                    else
                    {
                        median = (nums2[j] + nums2[j + 1]) / 2.0;
                        break;
                    }
                }
            }
        }

        return median;
    }
    */
};
// @lc code=end
