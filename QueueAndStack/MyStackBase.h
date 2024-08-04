#ifndef DATASTRUCTURE_MYSTACKBASE_H
#define DATASTRUCTURE_MYSTACKBASE_H

template <typename T>
class MyStackBase {
public:
    virtual ~MyStackBase() = default;
    virtual bool empty() const = 0;
    virtual int size() const = 0;
    virtual T& top() const = 0;
    virtual void pop() const = 0;
    virtual void push(const T& element) = 0;
};

#endif //DATASTRUCTURE_MYSTACKBASE_H
