/*
字谜分组
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
说明：

所有输入均为小写字母。
不考虑答案输出的顺序。
*/



/*
sort the word in the list individually, use the sorted the word as the key to the unordered_map
and add all the Anagrams words to the value of the key

the unordered_map looks like:
key -> value
aet -> ["ate","eat","tea"]
ant -> ["nat","tan"]
abt -> ["bat"]

then iterate through the unordered_map, push all the values to the result
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        // <key,value> : <aet, ["ate","eat","tea"]>
        unordered_map<string, vector<string>> um;
        // iterate through the input list
        for (int i = 0; i < strs.size(); i++)
        {
            // for every word, sort first to get the key
            string sorted = strs[i];
            sort(sorted.begin(), sorted.end());
            // if the key doesn't exist in the unordered_map
            if (um.find(sorted) == um.end())
            {
                // insert the value to the new key
                // the value is this word
                vector<string> v{strs[i]};
                um.insert({sorted, v});
            }
            // if the key is already in the unordered_map
            else
            {
                // take the value (a vector of strings) of the key
                // add back the new string to the vector
                um[sorted].push_back(strs[i]);
            }
        }

        vector<vector<string>> res;
        // iterate through the unordered_map
        for (unordered_map<string, vector<string>>::iterator it = um.begin(); it != um.end(); it++)
        {
            // for every key, iterate through the values (a vector of strings)
            vector<string> word;
            for (int i = 0; i < it->second.size(); i++)
            {
                // push the strings in the vector to a new vector
                word.push_back(it->second[i]);
            }
            // add the vector to the results.
            res.push_back(word);
        }
        return res;
    }
};
