#include <iostream>
#include <functional>
#include <queue>
#include <vector>

using namespace std;

/*
Success
Details 
Runtime: 220 ms, faster than 30.46% of C++ online submissions for Find Median from Data Stream.
Memory Usage: 40.3 MB, less than 100.00% of C++ online submissions for Find Median from Data Stream.
*/
class MedianFinder
{
private:
    std::priority_queue<int> lower;                             // default is max heap
    std::priority_queue<int, vector<int>, greater<int>> higher; // min heap
    double curMedian;

public:
    /** initialize your data structure here. */
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (higher.empty() && lower.empty())
        {
            lower.push(num);
            curMedian = num;
            return;
        }
        int curSize = higher.size() + lower.size();
        // currently there is odd numbers of element
        // lower top is the median
        // insert to make the two heaps balanced
        // after insert it's even number
        // take top from both and calculate the median
        if (curSize % 2 == 1)
        {
            if (num < lower.top())
            {
                lower.push(num);
                higher.push(lower.top());
                lower.pop();
            }
            else
            {
                higher.push(num);
            }
            curMedian = (lower.top() + higher.top()) / 2.0;
        }
        // currently it's even number of elements
        else
        {
            if (num < lower.top())
            {
                lower.push(num);
            }
            else if (num > higher.top())
            {
                higher.push(num);
                lower.push(higher.top());
                higher.pop();
            }
            else // in the middle, num is the median
            {
                lower.push(num);
            }
            curMedian = lower.top();
        }
    }

    double findMedian()
    {
        return curMedian;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main()
{
    MedianFinder *obj = new MedianFinder();
    obj->addNum(1);
    obj->addNum(2);
    cout << obj->findMedian() << endl;
    obj->addNum(3);
    cout << obj->findMedian() << endl;
}