// https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/1/array/27/
/*
加一
给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

示例 1:

输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123。
示例 2:

输入: [4,3,2,1]
输出: [4,3,2,2]
解释: 输入数组表示数字 4321。
*/
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int size = digits.size();
        int i = size - 1;
        int add = 0;
        int carry = 0;
        while (i >= 0)
        {
            add = (digits[i] + 1) % 10; // carry can only be 1
            carry = (digits[i] + 1) / 10;
            digits[i] = add;
            if(carry)
            {
                i--;
            }
            else
            {
                break;
            }
            
        }
        // need to add one more element to the vector
        if(carry)
        {
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};


int main()
{
    // vector<int> v{4,3,2,1};
    vector<int> v{9,9,9,9};
    Solution s;
    s.plusOne(v);
    for(auto x: v)
    {
        cout << x << " ";
    }
    cout << endl;
}