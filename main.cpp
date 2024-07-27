#include <iostream>
#include "LinearList/MySequentialList.h"
using namespace std;


int main()
{
    MySequentialList<int> my_list(3);
    cout << "Initial size is " << my_list.size() << endl;
    cout << "Initial capacity is " << my_list.capacity() << endl;

    my_list.insert(0, 1);
    my_list.insert(1, 2);
    my_list.insert(2, 3);
    cout << "Size is " << my_list.size() << endl;
    cout << "Capacity is " << my_list.capacity() << endl;
    for (int i = 0; i != my_list.size(); ++i)
        cout << my_list.get(i) << " ";
    cout << endl;

    my_list.insert(0, 1);
    my_list.insert(0, 2);
    my_list.insert(0, 3);
    cout << "Size is " << my_list.size() << endl;
    cout << "Capacity is " << my_list.capacity() << endl;
    for (int i = 0; i != my_list.size(); ++i)
        cout << my_list.get(i) << " ";
    cout << endl;

    my_list.insert(0, 0);
    cout << "Size is " << my_list.size() << endl;
    cout << "Capacity is " << my_list.capacity() << endl;
    for (int i = 0; i != my_list.size(); ++i)
        cout << my_list.get(i) << " ";
    cout << endl;

    my_list.insert(1, 0);
    cout << "Size is " << my_list.size() << endl;
    cout << "Capacity is " << my_list.capacity() << endl;
    cout << &my_list.get(0) << endl;

    my_list.insert(1, 0);
    cout << "Size is " << my_list.size() << endl;
    cout << "Capacity is " << my_list.capacity() << endl;
    cout << &my_list.get(0) << endl;

}
