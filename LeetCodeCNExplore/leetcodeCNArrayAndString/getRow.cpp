/*
杨辉三角 II
给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。



在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 3
输出: [1,3,3,1]
进阶：

你可以优化你的算法到 O(k) 空间复杂度吗？
*/


class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<vector<int>> res;
        for (int layer = 0; layer <= rowIndex; layer++)
        {
            if (layer == 0)
            {
                vector<int> thisLayer = {1};
                res.push_back(thisLayer);
            }
            else if (layer == 1)
            {
                vector<int> thisLayer = {1, 1};
                res.push_back(thisLayer);
            }
            else
            {
                vector<int> previousLayer = res[layer - 1];
                int thisLayerSize = layer + 1;
                vector<int> thisLayer(thisLayerSize, 0);
                thisLayer[0] = 1;
                thisLayer[thisLayerSize - 1] = 1;
                for (int i = 1; i < thisLayerSize - 1; i++)
                {
                    thisLayer[i] = previousLayer[i - 1] + previousLayer[i];
                }
                res.push_back(thisLayer);
            }
        }
        return res[rowIndex];
    }
};