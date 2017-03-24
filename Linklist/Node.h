#ifndef _NODE_H_
#define _NODE_H_

#include <cstdio>

template<class T>
class Node
{
public:
    Node(T data, Node<T> *next = NULL);
    void setData(T data);
    T& getData();
    const T& getData() const;
//     void setNext(Node<T> *node);
    Node<T> *nextNode();
    const Node<T> *nextNode() const;
    void insertAfter(Node<T> *p);
    Node<T> *deleteAfter();
private:
    T data;
    Node<T> *next;
};

template<class T>
Node<T>::Node(T data, Node<T>* next)
    : data(data), next(next)
{
}

template<class T>
T & Node<T>::getData()
{
    return data;
}

template<class T>
const T & Node<T>::getData() const
{
    return data;
}

template<class T>
void Node<T>::setData(T data)
{
    this->data = data;
}

// template<class T>
// void Node<T>::setNext(Node<T> *node)
// {
//     this->next = node;
// }

template<class T>
Node<T> * Node<T>::nextNode()
{
    return next;
}

template<class T>
const Node<T> * Node<T>::nextNode() const
{
    
    return next;
}

template<class T>
void Node<T>::insertAfter(Node<T>* p)
{
    p->next = this->next;
    this->next = p;
}

template<class T>
Node<T> * Node<T>::deleteAfter()
{
    if (next) {
        Node<T> *node = this->next;
        this->next = node->next;
        node->next = NULL;
        return node;
    }
    return NULL;
}

#endif
