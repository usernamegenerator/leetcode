/*
 Insert Delete GetRandom O(1)
设计一个支持在平均 时间复杂度 O(1) 下，执行以下操作的数据结构。

insert(val)：当元素 val 不存在时，向集合中插入该项。
remove(val)：元素 val 存在时，从集合中移除该项。
getRandom：随机返回现有集合中的一项。每个元素应该有相同的概率被返回。
示例 :

// 初始化一个空的集合。
RandomizedSet randomSet = new RandomizedSet();

// 向集合中插入 1 。返回 true 表示 1 被成功地插入。
randomSet.insert(1);

// 返回 false ，表示集合中不存在 2 。
randomSet.remove(2);

// 向集合中插入 2 。返回 true 。集合现在包含 [1,2] 。
randomSet.insert(2);

// getRandom 应随机返回 1 或 2 。
randomSet.getRandom();

// 从集合中移除 1 ，返回 true 。集合现在包含 [2] 。
randomSet.remove(1);

// 2 已在集合中，所以返回 false 。
randomSet.insert(2);

// 由于 2 是集合中唯一的数字，getRandom 总是返回 2 。
randomSet.getRandom();
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class RandomizedSet
{
private:
    vector<int> values;                                   // main data structure to store the element
    unordered_map<int, unordered_set<int>> value_indexes; // <value,a set of index>

public:
    /** Initialize your data structure here. */
    RandomizedSet()
    {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        bool res = false;
        if (value_indexes.find(val) == value_indexes.end()) // not found
        {
            res = true;
        }
        values.push_back(val);
        int index = values.size() - 1;
        value_indexes[val].insert(index);
        return res;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        if (value_indexes.find(val) == value_indexes.end()) // not found
        {
            return false;
        }
        // get the indexes to remove first
        int index = *value_indexes[val].begin();
        // remove the index from the unordered_set
        value_indexes[val].erase(index);
        // remove the value_indexes key
        if (value_indexes[val].empty())
        {
            value_indexes.erase(val);
        }

        // check if it's already the last element in the vector
        int lastIndex = values.size() - 1;
        // if so just delete it
        if (index == lastIndex)
        {
            values.pop_back();
            // everything was remove previously
        }
        else // if not, need to swap with the last element, delete, then update the value_indexes and unordered_set for the last element
        {
            int lastVal = values[lastIndex];
            // assign the last element to the removed index
            values[index] = lastVal;
            // remove the element
            values.pop_back();
            // update the last element, which has the index as "index" now
            value_indexes[lastVal].erase(lastIndex);
            value_indexes[lastVal].insert(index);
        }

        // continue to remove every val in case there are multiple
        while(value_indexes.find(val) != value_indexes.end())
        {
            remove(val);
        }

        return true;
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        int size = values.size();
        int ran = rand() % size;
        return values[ran];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main()
{
    RandomizedSet *obj = new RandomizedSet();
    cout << obj->insert(3) << endl;   // TRUE
    cout << obj->insert(-2) << endl;  // TRUE
    cout << obj->remove(2) << endl;   // FALSE
    cout << obj->insert(1) << endl;   // TRUE
    cout << obj->insert(-3) << endl;  // TRUE
    cout << obj->insert(-2) << endl;  // FALSE
    cout << obj->remove(-2) << endl;  // TRUE
    cout << obj->remove(3) << endl;   // TRUE
    cout << obj->insert(-1) << endl;  // TRUE
    cout << obj->remove(-3) << endl;  // TRUE
    cout << obj->insert(1) << endl;   // FALSE
    cout << obj->insert(-2) << endl;  // TRUE
    cout << obj->insert(-2) << endl;  // FALSE
    cout << obj->insert(-2) << endl;  // FALSE
    cout << obj->insert(1) << endl;   // FALSE
    cout << obj->getRandom() << endl; //-1
    cout << obj->insert(-2) << endl;  // FALSE
    cout << obj->remove(0) << endl;   // FALSE
    cout << obj->insert(-3) << endl;  // TRUE
    cout << obj->insert(1) << endl;   //FALSE
}