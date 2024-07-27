#ifndef DATASTRUCTURE_MYLISTBASE_H
#define DATASTRUCTURE_MYLISTBASE_H

template <typename T>
class MyLinearListBase {
public:
    virtual ~MyLinearListBase() = default;
    virtual bool empty() const = 0;
    virtual int size() const = 0;
    virtual T& get(int target_index) const = 0;
    virtual int indexOf(const T& element) const = 0;
    virtual void erase(int index) = 0;
    virtual void insert(int index, const T& element) = 0;
};

#endif //DATASTRUCTURE_MYLISTBASE_H
