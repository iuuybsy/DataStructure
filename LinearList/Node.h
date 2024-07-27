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
    Node<T>* next;
    Node<T>* previous;
    DoublyNode(): next(nullptr), previous(nullptr) {};
    DoublyNode(const T& val_): val(val_), next(nullptr), previous(nullptr) {};
};

#endif //DATASTRUCTURE_NODE_H
