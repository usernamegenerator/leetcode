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
    string longestPalindrome(string s)
    {
        int size = s.size();
        string maxString = "";
        // i is the center
        for (int i = 0; i < size; i++)
        {
            if (maxString.size() == 0)
            {
                maxString = s[i];
            }

            int j = i - 1;
            int k = i + 1;
            while (s[j] == s[i] && j >= 0)
            {
                string temp = s.substr(j, i - j + 1);
                if (temp.size() > maxString.size())
                    maxString = temp;
                j--;
            }
            while (s[k] == s[i] && k < size)
            {
                string temp = s.substr(i, k - i + 1);
                if (temp.size() > maxString.size())
                    maxString = temp;
                k++;
            }
            while (j >= 0 && k < size)
            {
                if (s[j] != s[k])
                    break;
                string temp = s.substr(j, k - j + 1);
                if (temp.size() > maxString.size())
                {
                    maxString = temp;
                }
                j--;
                k++;
            }
        }
        return maxString;
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
