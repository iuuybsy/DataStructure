#ifndef DATASTRUCTURE_NODE_H
#define DATASTRUCTURE_NODE_H

template <typename T>
class Node {
public:
    T val;
    T* next;
    Node(): next(nullptr) {};
    Node(T val_): val(val_), next(nullptr) {};
};

template <typename T>
class DoublyNode {
public:
    T val;
    T* next;
    T* previous;
    DoublyNode(): next(nullptr), previous(nullptr) {};
    DoublyNode(T val_): val(val_), next(nullptr), previous(nullptr) {};
};

#endif //DATASTRUCTURE_NODE_H
