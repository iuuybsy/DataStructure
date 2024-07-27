#ifndef DATASTRUCTURE_NODE_H
#define DATASTRUCTURE_NODE_H

template <typename T>
class Node {
public:
    T data;
    T* next;
    Node(): next(nullptr) {};
};

#endif //DATASTRUCTURE_NODE_H
