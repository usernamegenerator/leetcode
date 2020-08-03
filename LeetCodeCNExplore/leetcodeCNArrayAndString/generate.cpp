/*
杨辉三角
给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。



在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 5
输出:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res;
        for (int layer = 0; layer < numRows; layer++)
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
                thisLayer[thisLayerSize-1] = 1;
                for (int i = 1; i < thisLayerSize-1; i++)
                {
                    thisLayer[i] = previousLayer[i - 1] + previousLayer[i];
                }
                res.push_back(thisLayer);
            }
        }
        return res;
    }
};