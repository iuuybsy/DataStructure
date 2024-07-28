#include <iostream>
#include "LinearList/MySequentialList.h"
#include "LinearList/MyLinkedList.h"
#include "LinearList/MyDoublyLinkedList.h"
using namespace std;

void show(const MyDoublyLinkedList<int>& list) {
    int n = list.size();
    cout << "size is " << n << endl;
    for (int i = 0; i != n; ++i) {
        cout << list.get(i) << " ";
    }
    cout << endl << endl;
}

int main()
{
    MyDoublyLinkedList<int> list;
    int n = list.size();
    cout << "size is " << n << endl;

    for (int i = 0; i != 10; ++i) {
        list.insert(i, i);
        show(list);
    }

    for (int i = 0; i != 3; ++i) {
        list.erase(1);
        show(list);
    }

    cout << list.indexOf(4) << endl;
    cout << list.get(3) << endl;
}
