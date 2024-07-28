#ifndef DATASTRUCTURE_NODE_H
#define DATASTRUCTURE_NODE_H

template <typename T>
class Node {
public:
    T val;
    Node<T>* next;
    Node(): next(nullptr) {};
    Node(const T& val_): val(val_), next(nullptr) {};
};

template <typename T>
class DoublyNode {
public:
    T val;
    DoublyNode<T>* next;
    DoublyNode<T>* prev;
    DoublyNode(): next(nullptr), prev(nullptr) {};
    DoublyNode(const T& val_): val(val_), next(nullptr), prev(nullptr) {};
};

#endif //DATASTRUCTURE_NODE_H
