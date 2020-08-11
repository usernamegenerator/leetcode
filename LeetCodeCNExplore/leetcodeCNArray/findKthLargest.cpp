/*
数组中的第K个最大元素

在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
示例 2:

输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
说明:

你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/all-about-array/x90rpm/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution
{
private:
    void maxHeapify(vector<int> &nums, int idx, int heapSize)
    {
        int leftIdx = idx * 2 + 1;
        int rightIdx = idx * 2 + 2;
        int tempMax = idx;
        if (leftIdx < heapSize && nums[leftIdx] > nums[idx])
        {
            tempMax = leftIdx;
        }
        if (rightIdx < heapSize && nums[rightIdx] > nums[tempMax])
        {
            tempMax = rightIdx;
        }
        if (tempMax != idx)
        {
            swap(nums[tempMax], nums[idx]);
            maxHeapify(nums, tempMax, heapSize);
        }
    }

    void buildHeap(vector<int> &nums, int heapSize)
    {
        for (int i = heapSize / 2; i >= 0; i--)
        {
            maxHeapify(nums, i, heapSize);
        }
    }

public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int heapSize = nums.size();
        buildHeap(nums, heapSize);
        for (int i = 0; i < k-1; i++)
        {
            swap(nums[0], nums[heapSize - 1]);
            heapSize--;
            maxHeapify(nums, 0, heapSize);
        }
        return nums[0];
    }
};