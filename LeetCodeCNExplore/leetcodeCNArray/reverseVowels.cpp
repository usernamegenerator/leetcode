/*
反转字符串中的元音字母
编写一个函数，以字符串作为输入，反转该字符串中的元音字母。

示例 1:

输入: "hello"
输出: "holle"
示例 2:

输入: "leetcode"
输出: "leotcede"
说明:
元音字母不包含字母"y"。

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/all-about-array/x93lce/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution
{
private:
    bool isVowel(char c)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        {
            return true;
        }
        else
        {
            return false;
        }
    }

public:
    string reverseVowels(string s)
    {
        int i = 0;
        int j = s.size() - 1;
        while (i < j)
        {
            if (!isVowel(s[i]))
            {
                i++;
                continue;
            }
            if (!isVowel(s[j]))
            {
                j--;
                continue;
            }
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
};