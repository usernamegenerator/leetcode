// https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/

class Solution
{
private:
    map<char, string> m = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    vector<string> ans;
    string current;

public:
    void dfs(int index, string digits)
    {
        // the end
        if (index == digits.size())
        {
            ans.push_back(current);
            return;
        }

        // for this index
        char digit = digits[index];
        for (int i = 0; i < m[digit].size(); i++)
        {
            char letter = m[digit][i];
            current.push_back(letter);
            dfs(index + 1, digits);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if(digits.empty())
            return ans;
        int index = 0; // to index through the string digits
        dfs(index, digits);
        return ans;
    }
};