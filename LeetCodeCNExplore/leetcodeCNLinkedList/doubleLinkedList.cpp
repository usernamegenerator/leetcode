/*
设计链表
设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：val 和 next。val 是当前节点的值，next 是指向下一个节点的指针/引用。如果要使用双向链表，则还需要一个属性 prev 以指示链表中的上一个节点。假设链表中的所有节点都是 0-index 的。

在链表类中实现这些功能：

get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。
 

示例：

MyLinkedList linkedList = new MyLinkedList();
linkedList.addAtHead(1);
linkedList.addAtTail(3);
linkedList.addAtIndex(1,2);   //链表变为1-> 2-> 3
linkedList.get(1);            //返回2
linkedList.deleteAtIndex(1);  //现在链表是1-> 3
linkedList.get(1);            //返回3
 

提示：

所有val值都在 [1, 1000] 之内。
操作次数将在  [1, 1000] 之内。
请不要使用内置的 LinkedList 库。
*/
#include <iostream>
using namespace std;

class MyLinkedList
{
private:
    typedef struct DoubleListNode
    {
        DoubleListNode *next;
        DoubleListNode *prev;
        int val;
        DoubleListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
    } DoubleListNode;

    DoubleListNode *head;
    int size;

public:
    /** Initialize your data structure here. */
    MyLinkedList()
    {
        head = NULL;
        size = 0;
    }

    void printList()
    {
        DoubleListNode *cur = head;
        while (cur->next)
        {
            cout << cur->val << "-->";
            cur = cur->next;
        }
        cout << cur->val << endl;

        while (cur)
        {
            cout << cur->val << "<--";
            cur = cur->prev;
        }
        cout << endl;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        if (index < 0 || index >= size)
            return -1;
        int i = 0;
        DoubleListNode *cur = head;
        while (i < index)
        {
            cur = cur->next;
            i++;
        }
        return cur->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val)
    {
        if (head == NULL)
        {
            head = new DoubleListNode(val);
            size++;
            return;
        }
        DoubleListNode *newNode = new DoubleListNode(val);
        head->prev = newNode;
        newNode->next = head;
        newNode->prev = NULL;
        head = newNode;
        size++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        if (head == NULL)
        {
            head = new DoubleListNode(val);
            size++;
            return;
        }
        DoubleListNode *cur = head;
        while (cur->next)
        {
            cur = cur->next;
        }
        DoubleListNode *newNode = new DoubleListNode(val);
        cur->next = newNode;
        newNode->prev = cur;
        newNode->next = NULL;
        size++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        if (index < 0 || index > size)
        {
            return;
        }
        if (index == size)
        {
            addAtTail(val);
            return;
        }
        if (index == 0)
        {
            addAtHead(val);
            return;
        }
        int i = 0;
        DoubleListNode *cur = head;
        while (i < index - 1)
        {
            cur = cur->next;
            i++;
        }
        DoubleListNode *newNode = new DoubleListNode(val);
        DoubleListNode *after = cur->next;
        cur->next = newNode;
        after->prev = newNode;
        newNode->prev = cur;
        newNode->next = after;
        size++;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= size)
        {
            return;
        }
        if (index == 0)
        {
            head = head->next;
            size--;
            return;
        }
        int i = 0;
        DoubleListNode *cur = head;
        while (i < index - 1)
        {
            cur = cur->next;
            i++;
        }
        // check if the deleting node is the last node
        if (cur->next->next == NULL)
        {
            cur->next = NULL;
        }
        else
        {
            DoubleListNode *after = cur->next->next;
            cur->next = after;
            after->prev = cur;
        }
        size--;
        return;
    }
};

int main()
{
    MyLinkedList *obj = new MyLinkedList();
    /*
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1, 2);
    obj->printList();
    cout << obj->get(1) << endl;
    obj->deleteAtIndex(1);
    cout << obj->get(1) << endl;
    */

   /*
    obj->addAtHead(7);
    obj->addAtHead(2);
    obj->addAtHead(1);
    obj->addAtIndex(3,0);
    obj->deleteAtIndex(2);
    obj->addAtHead(6);
    obj->addAtTail(4);
    cout << obj->get(4) << endl;   
    obj->addAtHead(4);
    obj->addAtIndex(5,0);
    obj->addAtHead(6);
    obj->printList();
    */

    /*
    obj->addAtHead(2);
    obj->deleteAtIndex(1);
    obj->addAtHead(2);
    obj->addAtHead(7);
    obj->addAtHead(3);
    obj->addAtHead(2);
    obj->addAtHead(5);
    obj->addAtTail(5);
    obj->printList();
    cout << obj->get(5);
    obj->deleteAtIndex(6);
    obj->deleteAtIndex(4);
    */

   obj->addAtHead(4);
   cout << obj->get(1) << endl;
   obj->addAtHead(1);
   obj->addAtHead(5);
   obj->deleteAtIndex(3);
   obj->addAtHead(7);
   obj->get(3);
   obj->get(3);
   obj->get(3);
   obj->addAtHead(1);
   obj->deleteAtIndex(4);
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */