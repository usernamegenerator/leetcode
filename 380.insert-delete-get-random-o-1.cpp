/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 *
 * https://leetcode.com/problems/insert-delete-getrandom-o1/description/
 *
 * algorithms
 * Medium (45.78%)
 * Likes:    2373
 * Dislikes: 153
 * Total Accepted:    231.6K
 * Total Submissions: 491.7K
 * Testcase Example:  '["RandomizedSet","insert","remove","insert","getRandom","remove","insert","getRandom"]\n[[],[1],[2],[2],[],[1],[2],[]]'
 *
 * Design a data structure that supports all following operations in average
 * O(1) time.
 * 
 * 
 * 
 * insert(val): Inserts an item val to the set if not already present.
 * remove(val): Removes an item val from the set if present.
 * getRandom: Returns a random element from current set of elements. Each
 * element must have the same probability of being returned.
 * 
 * 
 * 
 * Example:
 * 
 * // Init an empty set.
 * RandomizedSet randomSet = new RandomizedSet();
 * 
 * // Inserts 1 to the set. Returns true as 1 was inserted successfully.
 * randomSet.insert(1);
 * 
 * // Returns false as 2 does not exist in the set.
 * randomSet.remove(2);
 * 
 * // Inserts 2 to the set, returns true. Set now contains [1,2].
 * randomSet.insert(2);
 * 
 * // getRandom should return either 1 or 2 randomly.
 * randomSet.getRandom();
 * 
 * // Removes 1 from the set, returns true. Set now contains [2].
 * randomSet.remove(1);
 * 
 * // 2 was already in the set, so return false.
 * randomSet.insert(2);
 * 
 * // Since 2 is the only number in the set, getRandom always return 2.
 * randomSet.getRandom();
 * 
 * 
 */

// @lc code=start
class RandomizedSet
{
private:
    vector<int> values;
    unordered_map<int, unordered_set<int>> value_index;

public:
    /** Initialize your data structure here. */
    RandomizedSet()
    {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        bool ret = false;
        // not found
        if (value_index.find(val) == value_index.end())
        {
            ret = true;
        }
        values.push_back(val);
        int index = values.size() - 1;
        value_index[val].insert(index);
        return ret;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        if (value_index.find(val) == value_index.end())
        {
            return false;
        }
        // always get the first element in the unordered set
        int index = *value_index[val].begin();
        // erase this element from the unordered set
        value_index[val].erase(index);
        // check if the set becomes empty, meaning the removed one was the only item
        // if so, then delete the entry
        if (value_index[val].empty())
        {
            value_index.erase(val);
        }
        // now remove this item from the values array
        // check if it is the last element in the array'
        // if so, remove directly then done
        if (index == values.size() - 1)
        {
            values.pop_back();
        }
        // if not, need to swap the index to the last
        // we assign the last element to the index, then just pop the last
        else
        {
            int lastIndex = values.size() - 1;
            int lastValue = values[lastIndex];
            values[index] = lastValue;
            values.pop_back();
            // update the lastValue's mapped position
            value_index[lastValue].erase(lastIndex);
            value_index[lastValue].insert(index);
        }

        // need to remove all the vals, so keep calling this function
        while (value_index.find(val) != value_index.end())
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
// @lc code=end
