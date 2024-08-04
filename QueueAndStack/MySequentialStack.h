#ifndef DATASTRUCTURE_MYSEQUENTIALSTACK_H
#define DATASTRUCTURE_MYSEQUENTIALSTACK_H

#include "MyStackBase.h"
#include "../LinearList/MySequentialList.h"

template <typename T>
class MySequentialStack: public MyStackBase<T> {
public:
    MySequentialStack();
    virtual ~MySequentialStack();

    virtual bool empty() const;
    virtual int size() const;
    virtual T& top() const;
    virtual void pop() const;
    virtual void push(const T& element);

protected:
    MySequentialList<T>* list;
};

template <typename T>
MySequentialStack<T>::MySequentialStack() {
    list = new MySequentialList<T>(10);
}

template <typename T>
MySequentialStack<T>::~MySequentialStack() {
    delete list;
    list = nullptr;
}

template <typename T>
bool MySequentialStack<T>::empty() const {
    return list->empty();
}

template <typename T>
int MySequentialStack<T>::size() const {
    return list->size();
}

template <typename T>
T& MySequentialStack<T>::top() const {
    return list->get(list->size() - 1);
}

template <typename T>
void MySequentialStack<T>::pop() const {
    list->erase(list->size() - 1);
}

template <typename T>
void MySequentialStack<T>::push(const T& element) {
    list->insert(list->size(), element);
}

#endif //DATASTRUCTURE_MYSEQUENTIALSTACK_H
