/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

#include <string>
#include <iostream>
using namespace std;
// @lc code=start
class Solution
{
public:
    /****************************************************/
    /*
// method 1:    
brute force
O(N^3)
Time Limit Exceeded
*/
    /*
    string longestPalindrome(string s)
    {
        int size = s.size();
        int i = 0;
        int j = 0;
        int returnMax = 0;
        string returnSubString = "";
        while (i < size)
        {
            j = i;
            while (j < size)
            {
                string subString = s.substr(i, j - i + 1);
                //cout << "checking substring " << subString << endl;
                if (isPalindromic(subString))
                {
                    if (subString.size() > returnMax)
                    {
                        returnSubString = subString;
                        returnMax = subString.size();
                    }
                }
                j++;
            }
            i++;
        }
        return returnSubString;
    }

    bool isPalindromic(string s)
    {
        int size = s.size();
        for (int i = 0, j = size - 1; i < j; i++, j--)
        {
            if (s[i] != s[j])
            {
                return false;
            }
        }
        //cout << s << endl;
        return true;
    }
*/
    /****************************************************/
    // method 2:
    // expland from center
    // filling # for abbc type (even centered)
    /*    string longestPalindrome(string s)
    {
        int size = s.size();
        string news;
        int i = 0;
        while (i < size)
        {
            news.append("#");
            news.append(1, s[i++]);
        }
        news.append("#");

        // cout << news << endl;

        int new_size = news.size();
        string maxWithPadding = "";
        for (i = 0; i < new_size; i++)
        {
            string localMaxWithPadding = getPalindrome(news, i);
            if (localMaxWithPadding.size() > maxWithPadding.size())
            {
                maxWithPadding = localMaxWithPadding;
            }
        }
        string res;
        for(i=0;i<maxWithPadding.size();i++)
        {
            if(maxWithPadding[i]=='#')
            {
                continue;
            }
            res.append(1,maxWithPadding[i]);
        }
        return res;
    }

    string getPalindrome(string s, int i)
    {
        int j = 0;
        while (i - j >= 0 && i + j < s.size())
        {
            if (s[i - j] != s[i + j])
            {
                break;
            }
            else
            {
                j++;
            }
        }
        j--;
        // cout << i - j << " " << j + j << endl;
        // cout << s.substr(i - j, j + j + 1)<<endl;
        return s.substr(i - j, j + j + 1);
    } */

    /***********************************************************/
    // method 3:
    // dynamic programming
    // https://www.youtube.com/watch?v=m2Mk9JN5T4A
    string longestPalindrome(string s)
    {
        int size = s.size();
        // 1. one letter, return
        if (size == 1 || size == 0)
        {
            return s;
        }
        /*         // 2. two letters, if same, return
        if (size == 2)
        {
            if (s[0] == s[1])
            {
                return s;
            }
            else
            {
                return s.substr(0, 1);
            }
        } */

        // 3. dynamic programming
        bool **isPalindrome = new bool *[size];
        for (int i = 0; i < size; i++)
        {
            isPalindrome[i] = new bool[size];
        }
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                isPalindrome[i][j] = false;
            }
        }
        string res = "";
        for (int i = 0; i < size; i++)
        {
            isPalindrome[i][i] = true;
            for (int j = 0; j <= i; j++)
            {
                // i - j <= 2 is to prevent the overflow of [i-1] [j+1]
                isPalindrome[i][j] = s[i] == s[j] && (i - j <= 2 || isPalindrome[i - 1][j + 1]) ;
                if (isPalindrome[i][j])
                {
                    if (i - j + 1 > res.size())
                    {
                        res = s.substr(j, i - j + 1);
                    }
                }
            }
        }
        return res;
    }
};

// @lc code=end

int main()
{
    Solution s;
    cout << s.longestPalindrome("babad") << endl;
    cout << s.longestPalindrome("ccc") << endl;
    cout << s.longestPalindrome("a") << endl;
    cout << s.longestPalindrome("bb") << endl;
    cout << s.longestPalindrome("cbbd") << endl;
    cout << s.longestPalindrome("tembwxtvddsttolegryohdlhxhycymqybzfzcbkzdwcekzfapmpfyeivfoeeqoqdhylziqpnyzuzeeutpqpalbddlliuehvkhqevgjdkskvphidcjmpcmetzwqkzcnxjcjywhfzplntbkuddmbcovearburjqyirbladcrhfkfdfgsmyhdsfmmxmslwkymkgaguilxghmfgaldcogtfnbqakctqtqakupwrxkmbjpmzqngwldmaugzizgwmediyzxevspxdwruyzrmnhchtxlgtb") << endl;
    cout << s.longestPalindrome("abcdasdfghjkldcba") << endl;
}
