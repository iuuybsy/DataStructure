#include <iostream>
#include "LinearList/MySequentialList.h"
#include "LinearList/MyLinkList.h"
using namespace std;

void show(const MyLinkList<int>& list) {
    int n = list.size();
    cout << "size is " << n << endl;
    for (int i = 0; i != n; ++i) {
        cout << list.get(i) << " ";
    }
    cout << endl << endl;
}

int main()
{
    MyLinkList<int> list;
    int n = list.size();
//    cout << "size is " << n << endl;

    for (int i = 0; i != 10; ++i) {
        list.insert(i, i);
        show(list);
    }

    cout << list.indexOf(4) << endl;
    cout << list.get(3) << endl;
}
