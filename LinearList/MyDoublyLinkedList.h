#ifndef DATASTRUCTURE_MYDOUBLYLINKEDLIST_H
#define DATASTRUCTURE_MYDOUBLYLINKEDLIST_H

#include <sstream>
#include "MyListBase.h"
#include "Node.h"

template <typename T>
class MyDoublyLinkedList: public MyLinearListBase<T> {
public:
    MyDoublyLinkedList(): head(nullptr), tail(nullptr), list_size(0) {};
    MyDoublyLinkedList(const MyDoublyLinkedList<T>& another);
    virtual ~MyDoublyLinkedList();

    virtual bool empty() const;
    virtual int size() const;
    virtual T& get(int target_index) const;
    virtual int indexOf(const T& element) const;
    virtual void erase(int index);
    virtual void insert(int index, const T& element);

private:
    int list_size;
    DoublyNode<T>* head;
    DoublyNode<T>* tail;
    void checkIndex(int index) const;
};

template <typename T>
MyDoublyLinkedList<T>::MyDoublyLinkedList(const MyDoublyLinkedList<T>& another):
list_size(0), head(nullptr), tail(nullptr) {
    int n = another.size();
    for (int i = 0; i != n; ++i)
        insert(i, another.get(i));
}

template <typename T>
MyDoublyLinkedList<T>::~MyDoublyLinkedList() {
    while (head != nullptr) {
        DoublyNode<T>* next_ptr = head->next;
        delete head;
        head = nullptr;
        head = next_ptr;
    }
}

template <typename T>
bool MyDoublyLinkedList<T>::empty() const {
    return this->list_size == 0;
}

template <typename T>
int MyDoublyLinkedList<T>::size() const {
    return this->list_size;
}

template <typename T>
void MyDoublyLinkedList<T>::checkIndex(int index) const
{
    if (index < 0 || index >= this->list_size)
    {
        std::ostringstream str;
        str << "Index out of range!";
        throw str;
    }
}

template <typename T>
T& MyDoublyLinkedList<T>::get(int target_index) const {
    this->checkIndex(target_index);
    DoublyNode<T>* target = head;
    for (int i = 0; i != target_index; ++i)
        target = target->next;
    return (*target).val;
}

template <typename T>
int MyDoublyLinkedList<T>::indexOf(const T& element) const {
    int index = -1, count = -1;
    DoublyNode<T>* target = head;
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
void MyDoublyLinkedList<T>::erase(int index) {
    this->checkIndex(index);
    int mid = list_size / 2;
    if (index <= mid) {
        if (index == 0) {
            DoublyNode<T>* old_head = head;
            head = head->next;
            head->prev = nullptr;
            delete old_head;
            old_head = nullptr;
        } else {
            int count = 0;
            DoublyNode<T>* fast_ptr = head;
            DoublyNode<T>* slow_ptr = head;
            while (count != index) {
                if (fast_ptr != head)
                    slow_ptr = slow_ptr->next;
                fast_ptr = fast_ptr->next;
                ++count;
            }
            DoublyNode<T>* target = fast_ptr;
            fast_ptr = fast_ptr->next;
            slow_ptr->next = fast_ptr;
            fast_ptr->prev = slow_ptr;
            delete target;
            target = nullptr;
        }
    } else {
        if (index == list_size - 1) {
            DoublyNode<T>* old_tail = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete old_tail;
            old_tail = nullptr;
        } else {
            int count = 1;
            DoublyNode<T>* fast_ptr = tail;
            DoublyNode<T>* slow_ptr = tail;
            while (count != list_size - index) {
                if (fast_ptr != tail)
                    slow_ptr = slow_ptr->prev;
                fast_ptr = fast_ptr->prev;
                ++count;
            }
            DoublyNode<T>* target = fast_ptr;
            fast_ptr = fast_ptr->prev;
            slow_ptr->prev = fast_ptr;
            fast_ptr->next= slow_ptr;
            delete target;
            target = nullptr;
        }
    }

    --list_size;
}

template <typename T>
void MyDoublyLinkedList<T>::insert(int index, const T& element) {
    if (index < 0 || index > list_size) {
        std::ostringstream str;
        str << "Index out of range!";
        throw str;
    } else if (list_size == 0) {
        head = new DoublyNode<T>(element);
        tail = head;
    } else {
        int mid = list_size / 2;
        if (index <= mid) {
            if (index == 0) {
                DoublyNode<T>* new_head = new DoublyNode<T>(element);
                new_head->next = head;
                head->prev = new_head;
                head = new_head;
                new_head = nullptr;
            } else {
                int count = 0;
                DoublyNode<T>* fast_ptr = head;
                DoublyNode<T>* slow_ptr = head;
                while (count != index) {
                    ++count;
                    if (fast_ptr != head)
                        slow_ptr = slow_ptr->next;
                    fast_ptr = fast_ptr->next;
                }
                DoublyNode<T>* target = new DoublyNode<T>(element);
                slow_ptr->next = target;
                target->prev = slow_ptr;
                target->next = fast_ptr;
                fast_ptr->prev = target;
            }
        } else {
            if (index == list_size) {
                DoublyNode<T>* new_tail = new DoublyNode<T>(element);
                tail->next = new_tail;
                new_tail->prev = tail;
                tail = new_tail;
                new_tail = nullptr;
            } else {
                int count = 0;
                DoublyNode<T>* fast_ptr = tail;
                DoublyNode<T>* slow_ptr = tail;
                while (count != list_size - index) {
                    ++count;
                    if (fast_ptr != tail)
                        slow_ptr = slow_ptr->prev;
                    fast_ptr = fast_ptr->prev;
                }
                DoublyNode<T>* target = new DoublyNode<T>(element);
                slow_ptr->prev = target;
                target->next = slow_ptr;
                target->prev = fast_ptr;
                fast_ptr->next = target;
            }
        }
    }
    ++list_size;
}

#endif //DATASTRUCTURE_MYDOUBLYLINKEDLIST_H
