#ifndef _LINKLIST_H_
#define _LINKLIST_H_

#include "Node.h"

template<class T>
class LinkList
{
public:
    LinkList();
    LinkList(const LinkList<T> &L);
    LinkList<T> & operator = (const LinkList<T> &L);
    ~LinkList();
    
    void reset();
    int getSize() const;
    int currPosition() const;
    bool isEmpty() const;
    bool isEnd() const;
    T &data();
    const T &data() const;
    void next();
    // add item
    void insertFront(const T &item);
    void insertRear(const T &item);
    void insertAt(const T &item);
    void insertAfter(const T&item);
    // delete item
    T deleteFront();
    void deleteCurrent();
    void clear();
    
private:
    Node<T> *newNode(const T &data, Node<T> *ptrNext = NULL);
    void freeNode(Node<T> *node);
    void copy(const LinkList<T> &L);
    
private:
    Node<T> *front, *rear;
    Node<T> *currPtr;
    int size;
    int position;
};

template<class T>
LinkList<T>::LinkList()
    : currPtr(NULL), size(0), position(0)
{
    front = NULL;
    rear = NULL;
}

template<class T>
LinkList<T>::~LinkList()
{
    clear();
    size = 0;
    position = 0;
}

template<class T>
Node<T> * LinkList<T>::newNode(const T& data, Node<T>* ptrNext)
{
    Node<T> *node = new Node<T>(data, ptrNext);
    return node;
}

template<class T>
void LinkList<T>::freeNode(Node<T>* node)
{
    delete node;
}

template<class T>
void LinkList<T>::reset()
{
    currPtr = front;
    position = currPtr == NULL ? 0 : 1;
}

template<class T>
int LinkList<T>::currPosition() const
{
    return position;
}

template<class T>
int LinkList<T>::getSize() const
{
    return size;
}

template<class T>
T & LinkList<T>::data()
{
    if (currPtr)
        return currPtr->getData();
}

template<class T>
const T & LinkList<T>::data() const
{
    if (currPtr)
        return currPtr->getData();
}

template<class T>
void LinkList<T>::next()
{
    currPtr = currPtr->nextNode();
    position++;
}

template<class T>
void LinkList<T>::insertFront(const T& item)
{
    Node<T> *node = newNode(item);
    size++;
    position++;
    currPtr = node;
    if (!front) {
        front = node;
        rear = node;
    } else {
        node->insertAfter(front);
        front = node;
    }
}

template<class T>
void LinkList<T>::insertRear(const T& item)
{
    Node<T> *node = newNode(item);
    size++;
    position++;
    currPtr = node;
    if (!rear) {
        rear = node;
        front = node;
    } else {
        rear->insertAfter(node);
        rear = node;
    }
}

template<class T>
bool LinkList<T>::isEmpty() const
{
    return (size == 0);
}

template<class T>
bool LinkList<T>::isEnd() const
{
    return (currPtr == NULL);
}

template<class T>
void LinkList<T>::clear()
{
    while (front) {
        Node<T> *node = front;
        front = front->nextNode();
        freeNode(node);
    }
}


#endif
