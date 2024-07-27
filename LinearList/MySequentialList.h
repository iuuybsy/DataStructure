#ifndef DATASTRUCTURE_MYSEQUENTIALLIST_H
#define DATASTRUCTURE_MYSEQUENTIALLIST_H

#include <sstream>
#include "MyListBase.h"

template <typename T>
class MySequentialList: public MyLinearListBase<T> {
public:
    MySequentialList(int initial_capacity);
    MySequentialList(const MySequentialList<T>& another);
    virtual ~MySequentialList();

    virtual bool empty() const;
    virtual int size() const;
    virtual int capacity() const;
    virtual T& get(int target_index) const;
    virtual int indexOf(const T& element) const;
    virtual void erase(int index);
    virtual void insert(int index, const T& element);

private:
    int list_capacity;
    int list_size;
    T* elements;

    void checkIndex(int index) const;
};

template <typename T>
MySequentialList<T>::MySequentialList(int initial_capacity)
{
    if (initial_capacity < 1)
    {
        std::ostringstream str;
        str << "The input capacity must bigger than 0!";
        throw str;
    }
    this->list_capacity = initial_capacity;
    this->list_size = 0;
    this->elements = new T[initial_capacity];
}

template <typename T>
MySequentialList<T>::MySequentialList(const MySequentialList<T>& another)
{
    this->list_capacity = another.capacity();
    this->list_size = another.size();
    this->T = new T[this->list_capacity];
    std::copy(another.elements, another.elements + this->list_size, elements);
}

template <typename T>
MySequentialList<T>::~MySequentialList()
{
    delete [] this->elements;
    this->elements = nullptr;
}

template <typename T>
void MySequentialList<T>::checkIndex(int index) const
{
    if (index < 0 || index >= this->list_size)
    {
        std::ostringstream str;
        str << "Index out of range!";
        throw str;
    }
}

template <typename T>
bool MySequentialList<T>::empty() const
{
    return this->list_size == 0;
}

template <typename T>
int MySequentialList<T>::size() const
{
    return this->list_size;
}

template <typename T>
int MySequentialList<T>::capacity() const
{
    return this->list_capacity;
}

template <typename T>
T& MySequentialList<T>::get(int target_index) const
{
    this->checkIndex(target_index);
    return elements[target_index];
}

template <typename T>
int MySequentialList<T>::indexOf(const T& element) const
{
    int target_index = -1;
    for (int i = 0; i != this->list_size; ++i)
    {
        if (*(elements + i) == element)
        {
            target_index = i;
            break;
        }
    }
    return target_index;
}

template <typename T>
void MySequentialList<T>::erase(int index)
{
    this->checkIndex(index);
    std::copy(elements + index + 1, elements + this->list_size, elements + index);
    --(this->list_size);
}

template <typename T>
void MySequentialList<T>::insert(int index, const T& element)
{
    if (index < 0 || index > this->list_size)
    {
        std::ostringstream str;
        str << "Index out of range!";
        throw str;
    }
    if (this->list_size == this->list_capacity)
    {
        T* new_elements = new T[2 * this->list_capacity];
        std::copy(this->elements, this->elements + this->list_size, new_elements);
        delete [] elements;
        elements = new_elements;
        this->list_capacity *= 2;
    }
    if (index != this->list_size)
        std::copy(elements + index, elements + list_size, elements + index + 1);
    elements[index] = element;
    ++this->list_size;
}

#endif //DATASTRUCTURE_MYSEQUENTIALLIST_H
