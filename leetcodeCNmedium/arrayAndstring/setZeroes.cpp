/*
 矩阵置零
给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。

示例 1:

输入: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
输出: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
示例 2:

输入: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
输出: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
进阶:

一个直接的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
你能想出一个常数空间的解决方案吗？
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    /*
    // extra space (M*N)
    // use another copy matrix, iterate through the copy matrix and setting the original matrix
    void setZeroes(vector<vector<int>> &matrix)
    {
        vector<vector<int>> copyMatrix = matrix;
        int numOfRows = matrix.size();
        int numOfCols = matrix[0].size();
        for (int i = 0; i < numOfRows; i++)
        {
            for (int j = 0; j < numOfCols; j++)
            {
                if (copyMatrix[i][j] == 0)
                {
                    for (int k = 0; k < numOfCols; k++)
                    {
                        matrix[i][k] = 0;
                    }
                    for (int k = 0; k < numOfRows; k++)
                    {
                        matrix[k][j] = 0;
                    }
                }
            }
        }
    }
    */

    /*
    // extra space (M+N)
    // use two 1D vector, one stores which row needs to be set to 0,
    // the other stores which col needs to be set to 0
    // iterate through the two vectors seprately
    // set the matrix accordingly
    void setZeroes(vector<vector<int>> &matrix)
    {
        int numOfRows = matrix.size();
        int numOfCols = matrix[0].size();
        vector<bool> rowToZeros(numOfRows, 0);
        vector<bool> colToZeros(numOfCols, 0);
        for (int i = 0; i < numOfRows; i++)
        {
            for (int j = 0; j < numOfCols; j++)
            {
                if (matrix[i][j] == 0)
                {
                    rowToZeros[i] = 1;
                    colToZeros[j] = 1;
                }
            }
        }

        for (int i = 0; i < numOfRows; i++)
        {
            if (rowToZeros[i] == 1)
            {
                for (int j = 0; j < numOfCols; j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = 0; j < numOfCols; j++)
        {
            if (colToZeros[j] == 1)
            {
                for (int i = 0; i < numOfRows; i++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
    */

    // find the first 0, for example matrix[row][col]
    // then use matrix[row][j] and matrix[i][col] as the marker vector in method 2
    // iterate through the matrix, set the marker vector
    // iterate through the marker vectors, set the matrix
    // at last, set two marker vectors as zeros
    void setZeroes(vector<vector<int>> &matrix)
    {

    }
};