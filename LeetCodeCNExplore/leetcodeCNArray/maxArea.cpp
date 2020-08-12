/*
盛最多水的容器
给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。

 



图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。

 

示例：

输入：[1,8,6,2,5,4,8,3,7]
输出：49

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/all-about-array/x96n4v/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution
{
private:
    int getArea(int leftIdx, int rightIdx, vector<int> &height)
    {
        int b = rightIdx - leftIdx;
        int h = min(height[leftIdx], height[rightIdx]);
        return b * h;
    }

public:
    int maxArea(vector<int> &height)
    {
        int i = 0;
        int j = height.size() - 1;
        int maxA = -1;
        /*
        for (int i = 0; i < height.size(); i++)
        {
            for (int j = i + 1; j < height.size(); j++)
            {
                int thisA = getArea(i, j, height);
                if (thisA > maxA)
                {
                    maxA = thisA;
                }
            }
        }
        */
        while (i < j)
        {
            int thisA = getArea(i, j, height);
            if (thisA > maxA)
            {
                maxA = thisA;
            }
            if(height[i] < height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return maxA;
    }
};