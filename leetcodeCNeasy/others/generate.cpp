// https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/26/others/67/

/*
 帕斯卡三角形
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
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        if (numRows == 0)
            return {};
        if (numRows == 1)
        {
            return {{1}};
        }
        if (numRows == 2)
        {
            return {{1}, {1, 1}};
        }

        vector<vector<int>> res;
        res.push_back({1});
        res.push_back({1, 1});

        for (int i = 2; i < numRows; i++)
        {
            // the ith row has i+1 elements
            int sizeOfthisRow = i + 1;
            vector<int> ithRow(sizeOfthisRow, 0);
            vector<int> preRow = res[i - 1];

            ithRow[0] = 1;
            // int row i, calculation index j started with index 1, end with index i-1;
            // (row)[j] = (row-1)[j-1] + (row-1)[j]
            for (int j = 1; j < sizeOfthisRow - 1; j++)
            {
                ithRow[j] = preRow[j - 1] + preRow[j];
            }
            // ithRow.push_back(1);
            ithRow[sizeOfthisRow - 1] = 1;
/*
            for (int j = 0; j < ithRow.size(); j++)
            {
                cout << ithRow[j] << ", ";
            }
            cout << endl;
*/
            res.push_back(ithRow);
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> res = s.generate(5);
    for (int i = 0; i < res.size(); i++)
    {
        vector<int> row = res[i];
        for (int j = 0; j < row.size(); j++)
        {
            cout << row[j] << ", ";
        }
        cout << endl;
    }
}