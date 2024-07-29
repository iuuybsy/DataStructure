#ifndef DATASTRUCTURE_NODE_H
#define DATASTRUCTURE_NODE_H

template <typename T>
class ListNode {
public:
    T val;
    ListNode<T>* next;
    ListNode(): next(nullptr) {};
    ListNode(const T& val_): val(val_), next(nullptr) {};
};

template <typename T>
class DoublyListNode {
public:
    T val;
    DoublyListNode<T>* next;
    DoublyListNode<T>* prev;
    DoublyListNode(): next(nullptr), prev(nullptr) {};
    DoublyListNode(const T& val_): val(val_), next(nullptr), prev(nullptr) {};
};

#endif //DATASTRUCTURE_NODE_H