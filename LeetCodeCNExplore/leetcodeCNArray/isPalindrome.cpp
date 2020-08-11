/*
验证回文串
您已有成功提交记录，请确认是否跳过？

跳过即视为本节
已完成


跳过

重新做题
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true
示例 2:

输入: "race a car"
输出: false

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/all-about-array/x9tqjc/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int i = 0;
        int j = s.size() - 1;
        while (i < j)
        {
            if (!isalpha(s[i]) && !isdigit(s[i]))
            {
                i++;
                continue;
            }
            if (!isalpha(s[j]) && !isdigit(s[j]))
            {
                j--;
                continue;
            }
            if (tolower(s[i]) != tolower(s[j]))
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};