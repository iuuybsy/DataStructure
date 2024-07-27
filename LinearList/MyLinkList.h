#ifndef DATASTRUCTURE_MYLINKLIST_H
#define DATASTRUCTURE_MYLINKLIST_H

#include <sstream>
#include "MyListBase.h"
#include "Node.h"

template <typename T>
class MyLinkList: public MyLinearListBase<T> {
public:
    MyLinkList(): head(nullptr), list_size(0) {};
    MyLinkList(const MyLinkList<T>& another);

    virtual ~MyLinkList();
    virtual bool empty() const;
    virtual int size() const;
    virtual T& get(int target_index) const;
    virtual int indexOf(const T& element) const;
    virtual void erase(int index);
    virtual void insert(int index, const T& element);

private:
    int list_size;
    Node<T>* head;
    void checkIndex(int index) const;
};

template <typename T>
MyLinkList<T>::MyLinkList(const MyLinkList<T>& another): list_size(0), head(nullptr) {
    int n = another.size();
    for (int i = 0; i != n; ++i) {
        this->insert(i, another.get(i));
    }
}

template <typename T>
MyLinkList<T>::~MyLinkList() {
    while (head != nullptr) {
        Node<T>* next_ptr = head->next;
        delete head;
        head = nullptr;
        head = next_ptr;
    }
}

template <typename T>
bool MyLinkList<T>::empty() const {
    return this->list_size == 0;
}

template <typename T>
int MyLinkList<T>::size() const {
    return this->list_size;
}

template <typename T>
void MyLinkList<T>::checkIndex(int index) const
{
    if (index < 0 || index >= this->list_size)
    {
        std::ostringstream str;
        str << "Index out of range!";
        throw str;
    }
}

template <typename T>
T& MyLinkList<T>::get(int target_index) const {
    this->checkIndex(target_index);
    Node<T>* target = head;
    for (int i = 0; i != target_index; ++i)
        target = target->next;
    return (*target).val;
}

template <typename T>
int MyLinkList<T>::indexOf(const T& element) const {
    int index = -1, count = -1;
    Node<T>* target = head;
    while(target) {
        ++count;
        if ((*target).val == element) {
            index= count;
            break;
        }
        target = target->next;
    }
    return index;
}

template <typename T>
void MyLinkList<T>::erase(int index) {
    this->checkIndex(index);
    if (index == 0) {
        Node<T>* temp_ptr = head->next;
        delete head;
        head = temp_ptr;
    } else {
        int count = 0;
        Node<T>* fast_ptr = head;
        Node<T>* slow_ptr = head;
        while (count != index) {
            if (fast_ptr != head)
                slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next;
            ++count;
        }
        slow_ptr->next = fast_ptr->next;
        delete fast_ptr;
        fast_ptr = nullptr;
    }
    --list_size;
}

template <typename T>
void MyLinkList<T>::insert(int index, const T& element) {
    if (index == 0) {
        Node<T>* old_head = head;
        head = new Node<T>(element);
        head->next = old_head;
    } else if (index == this->list_size) {
        Node<T>* ptr = head;
        while(ptr->next)
            ptr = ptr->next;
        ptr->next = new Node<T>(element);
    } else if (index < 0 || index > list_size) {
        std::ostringstream str;
        str << "Index out of range!";
        throw str;
    } else {
        int count = -1;
        Node<T>* fast_ptr = head;
        Node<T>* slow_ptr = head;
        while (count != index) {
            ++count;
            if (fast_ptr != head)
                slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next;
        }
        slow_ptr->next = new Node<T>(element);
        slow_ptr->next->next = fast_ptr;
    }
    ++list_size;
}

#endif //DATASTRUCTURE_MYLINKLIST_H
