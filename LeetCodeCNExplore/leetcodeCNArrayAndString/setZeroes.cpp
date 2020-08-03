/*
零矩阵
编写一种算法，若M × N矩阵中某个元素为0，则将其所在的行与列清零。

 

示例 1：

输入：
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
输出：
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
示例 2：

输入：
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
输出：
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size()==0)
            return;
        int numOfRows = matrix.size();
        int numOfCols = matrix[0].size();
        int indexingRow = -1;
        int indexingCol = -1;
        bool isFound = false;
        // find first zero element, use this row and col as the indexing
        // to indicate which row or col in the matrix needs to be set to 0
        for(int i =0;i<numOfRows;i++)
        {
            if(isFound)
            {
                break;
            }
            for(int j = 0;j<numOfCols;j++)
            {
                if(matrix[i][j]==0)
                {
                    isFound=true;
                    indexingRow = i;
                    indexingCol = j;
                    break;
                }
            }
        }
        if(!isFound)
            return;
        
        // iterate through the matrix and set the indexing row and col
        for(int i =0;i<numOfRows;i++)
        {
            if(i==indexingRow)
                continue;
            for(int j = 0;j<numOfCols;j++)
            {
                if(j==indexingCol)
                    continue;
                if(matrix[i][j]==0)
                {
                    matrix[indexingRow][j] = 0;
                    matrix[i][indexingCol] = 0;
                }
            }
        }
        
        // iterate through the indexing row and col, set the rest row and col to 0
        for(int j = 0; j < numOfCols; j++)
        {
            if(j==indexingCol)
                continue;
            if(matrix[indexingRow][j]==0)
            {
                for(int i = 0 ; i < numOfRows;i++)
                {
                    if(i==indexingRow)
                        continue;
                    matrix[i][j] = 0;
                }
            }
        }
        
        for(int i = 0; i < numOfRows; i++)
        {
            if(i==indexingRow)
                continue;
            if(matrix[i][indexingCol]==0)
            {
                for(int j = 0 ; j < numOfCols; j++)
                {
                    if(j==indexingCol)
                        continue;
                    matrix[i][j] = 0;
                }
            }
        }
        
        // set the indexing row and col itself to all 0
        for(int i = 0;i<numOfRows;i++)
        {
            matrix[i][indexingCol]=0;
        }
        for(int j = 0;j<numOfCols;j++)
        {
            matrix[indexingRow][j]=0;
        }
    }
};