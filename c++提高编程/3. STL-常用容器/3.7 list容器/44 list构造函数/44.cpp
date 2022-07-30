#include <iostream>
using namespace std;
#include <list>
void printList(const list<int> &L)
{
    for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
void test01()
{
    list<int> L1; // list<T> lst;
    for (int i = 0; i < 4; i++)
    {
        L1.push_back(i);
    }
    printList(L1);

    list<int> L2(++L1.begin(), L1.end()); // list(beg,end);
    printList(L2);

    list<int> L3(6, 6); // 6 6 6 6 6 6
    printList(L3);

    list<int> L4(L1); // 0 1 2 3
    printList(L4);
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
list<T> lst;
list(beg,end);
list(n,elem);
list(const list &lst); //拷贝构造
***********************************/