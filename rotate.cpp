// https://leetcode-cn.com/explore/featured/card/top-interview-questions-easy/1/array/23/
/*
 旋转数组
给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: [1,2,3,4,5,6,7] 和 k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右旋转 1 步: [7,1,2,3,4,5,6]
向右旋转 2 步: [6,7,1,2,3,4,5]
向右旋转 3 步: [5,6,7,1,2,3,4]
示例 2:

输入: [-1,-100,3,99] 和 k = 2
输出: [3,99,-1,-100]
解释: 
向右旋转 1 步: [99,-1,-100,3]
向右旋转 2 步: [3,99,-1,-100]
说明:

尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
要求使用空间复杂度为 O(1) 的 原地 算法。
*/

//k = 3
// 5,6,7,1,2,3,4
// 0 1 2 3 4 5 6  size = 7
//                 replaced
// 1 2 3 4 5 6 7 | 1
// 1 2 3 1 5 6 7 | 4
// 1 2 3 1 5 6 4 | 7
// 1 2 7 1 5 6 4 | 3
// 1 2 7 1 5 3 4 | 6
// 1 6 7 1 5 3 4 | 2
// 1 6 7 1 2 3 4 | 5
// 5 6 7 1 2 3 4 | 1
#include <iostream>
using namespace std;

void rotate(int *nums, int numsSize, int k)
{
    if (numsSize == 0 || numsSize == 1)
        return;
    if (k == 0)
        return;

    int iteration = 0;
    int start = 0;
    int replaced = nums[start];
    int destinationIndex = start + k;

    while (iteration < numsSize)
    {
        if (destinationIndex > numsSize - 1)
        {
            destinationIndex = destinationIndex % numsSize;
        }
        // cout << "destinationIndex " << destinationIndex << " ";
        //1. 把要替换的值暂存
        int newReplaced = nums[destinationIndex];
        // cout << "temp save " << newReplaced << " ";
        //2. 替换
        nums[destinationIndex] = replaced;
        // 如果回到最初开始的地方
        // 比如
        // 1, 2, 3, 4, 5, 6 . k = 2
        // 1, 2, 1, 4, 5, 6 | 3
        // 1, 2, 1, 4, 3, 6 | 5
        // 5, 2, 1, 4 ,3, 6
        // 从下一个index开始
        // 暂存的值要变成下一个index，新开始的index，的值
        if (destinationIndex == start)
        {
            destinationIndex++;
            //如果越界，需要修正
            if (destinationIndex > numsSize - 1)
            {
                destinationIndex = destinationIndex % numsSize;
            }
            start++;
            newReplaced = nums[destinationIndex];
        }

        // cout << "new value " << nums[destinationIndex] << " ";
        //3. 保存被替换的值
        replaced = newReplaced;
        //4. 计算新的替换位置
        destinationIndex = destinationIndex + k;
        // cout << "new dest " << destinationIndex << endl;

        /* for (int i = 0; i < numsSize; i++)
        {
            printf("%d ", nums[i]);
        }
        cout << endl;
 */
        iteration++;
    }
}

int main()
{
    int nums[] = {1, 2, 3, 4, 5, 6};
    rotate(nums, sizeof(nums) / sizeof(int), 2);
    for (int i = 0; i < sizeof(nums) / sizeof(int); i++)
    {
        printf("%d ", nums[i]);
    }
}