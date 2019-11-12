// https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/5/strings/35/
/*
  有效的字母异位词
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

示例 1:

输入: s = "anagram", t = "nagaram"
输出: true
示例 2:

输入: s = "rat", t = "car"
输出: false
说明:
你可以假设字符串只包含小写字母。

进阶:
如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
*/
#include <string>
using namespace std;

class Solution
{
public:
    // method 1: sort two strings, and compare from the beginning,
    // if they are anagram, then the two are exactly the same
    //O(nlogn)

    // method 2: have a counter for 26 letter (or 256 acsii)
    // iterate through s, add letter to the counter
    // iterate through s, decrese the counter
    // iterate throug the counter array, if all zero, then it's anagram
    //O(n)
    bool isAnagram(string s, string t)
    {
        int counter[26] = {0};
        for (int i = 0; i < s.size(); i++)
        {
            counter[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++)
        {
            counter[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (counter[i] != 0)
                return false;
        }
        return true;
    }
};