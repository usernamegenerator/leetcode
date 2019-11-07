// https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/25/math/61/

/*
计数质数
统计所有小于非负整数 n 的质数的数量。

示例:

输入: 10
输出: 4
解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    // over time limit
    /*
    int countPrimes(int n)
    {
        if(n==0 || n ==1 || n==2)
            return 0;
        int count = 1; // for 2
        bool notPrime = false;
        for (int i = 3; i < n; i++)
        {
            for (int j = 2; j < i; j++)
            {
                if (i % j == 0)
                {
                    notPrime = true;
                    break;
                }
            }
            if(notPrime == false)
                count++;
            else
                notPrime = false;
        }
        return count;
    }
    */
    // https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
    int countPrimes(int n)
    {
        if (n == 0 || n == 1 || n == 2)
            return 0;
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = 0;
        isPrime[1] = 0;
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (isPrime[i])
            {
                for (int j = i * i; j <= n; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (isPrime[i])
                cnt++;
        }
        return cnt;
    }
};

int main()
{
}