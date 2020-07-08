// https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/5/strings/33/

/*
整数反转
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:

输入: 123
输出: 321
 示例 2:

输入: -123
输出: -321
示例 3:

输入: 120
输出: 21
注意:

假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。
*/
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
class Solution
{
public:
    int reverse(int x)
    {
        vector<int> v;
        int save = x;
        
        while (x)
        {
            v.push_back(x % 10);
            x = x / 10;
        }
        /*
        for (auto i : v)
            cout << i;
        cout << endl;
        */

        double sum = 0;
        int p = 0;
        for (int i = v.size() - 1; i >= 0; i--)
        {
            /*
            cout << "pow has precise problems, results save to int is incorrect" << endl;
            cout << pow(10, p) << endl;
            int hello = pow(10, p);
            cout << hello << endl;
            */
            double tempSum = v[i] * pow(10, p);
            sum = sum + tempSum;
            p++;
        }

        if (sum > pow(2, 31) - 1 || sum < 0 - pow(2, 31))
            return 0;
            
        return (int)sum;
    }
};

int main()
{
    Solution s;
    cout << s.reverse(-123) << endl;
}