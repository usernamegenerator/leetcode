/*
对角线遍历
给定一个含有 M x N 个元素的矩阵（M 行，N 列），请以对角线遍历的顺序返回这个矩阵中的所有元素，对角线遍历如下图所示。

 

示例:

输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

输出:  [1,2,4,7,5,3,6,8,9]

解释:

 

说明:

给定矩阵中的元素总数不会超过 100000 。
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;
        int numOfRows = matrix.size();
        if (numOfRows == 0)
            return res;
        int numOfCols = matrix[0].size();
        int numOfElements = numOfRows * numOfCols;
        bool directionUp = true;
        int row = 0;
        int col = 0;
        int i = 0;
        while (i < numOfElements)
        {
            res.push_back(matrix[row][col]);
            if (directionUp)
            {
                if (row - 1 >= 0 && col + 1 < numOfCols) // next still within boundary
                {
                    row--;
                    col++;
                    i++;
                }
                else if (col + 1 >= numOfCols) // next hit the right boundary
                {
                    cout << " test " << endl;
                    row++;
                    i++;
                    directionUp = false;
                }
                else if (row - 1 < 0) // next hit the top boundary
                {
                    
                    col++;
                    i++;
                    directionUp = false;
                }
            }
            else
            {
                if (row + 1 < numOfRows && col - 1 >= 0) // next still within boundary
                {
                    row++;
                    col--;
                    i++;
                }
                else if (row + 1 >= numOfRows) // next hit the bottom boundary
                {
                    col++;
                    i++;
                    directionUp = true;
                }
                else if (col - 1 < 0) // next hit the left boundary
                {
                    row++;
                    i++;
                    directionUp = true;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix = {{2, 3}};
    /*
    vector<vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    */
    vector<int> res = s.findDiagonalOrder(matrix);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}