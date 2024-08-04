#ifndef DATASTRUCTURE_MYLINKEDSTACK_H
#define DATASTRUCTURE_MYLINKEDSTACK_H

#include "MyStackBase.h"
#include "../LinearList/MyLinkedList.h"

template <typename T>
class MyLinkedStack: public MyStackBase<T> {
public:
    MyLinkedStack();
    virtual ~MyLinkedStack();

    virtual bool empty() const;
    virtual int size() const;
    virtual T& top() const;
    virtual void pop() const;
    virtual void push(const T& element);

protected:
    MyLinkedList<T>* list;
};

template <typename T>
MyLinkedStack<T>::MyLinkedStack() {
    list = new MyLinkedList<T>(10);
}

template <typename T>
MyLinkedStack<T>::~MyLinkedStack() {
    delete list;
    list = nullptr;
}

template <typename T>
bool MyLinkedStack<T>::empty() const {
    return list->empty();
}

template <typename T>
int MyLinkedStack<T>::size() const {
    return list->size();
}

template <typename T>
T& MyLinkedStack<T>::top() const {
    return list->get(list->size() - 1);
}

template <typename T>
void MyLinkedStack<T>::pop() const {
    list->erase(list->size() - 1);
}

template <typename T>
void MyLinkedStack<T>::push(const T& element) {
    list->insert(list->size(), element);
}
#endif //DATASTRUCTURE_MYLINKEDSTACK_H
