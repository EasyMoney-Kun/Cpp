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
    list<int> L; // list<T> lst;
    for (int i = 0; i < 4; i++)
    {
        L.push_back(i);
    }
    printList(L);

    list<int> L1; // assign(beg,end);
    L1.assign(L.begin(), L.end());
    printList(L1);

    list<int> L2; // assign(n,elem);
    L2.assign(6, 6);
    printList(L2);

    list<int> L3; // list& operator=(const list &list);
    L3 = L2;
    printList(L3);
}
void test02()
{
    cout << "交换前：" << endl;
    list<int> L; // list<T> lst;
    for (int i = 0; i < 4; i++)
    {
        L.push_back(i);
    }
    printList(L);
    list<int> L2; // assign(n,elem);
    L2.assign(6, 6);
    printList(L2);

    cout << "交换后：" << endl;
    L.swap(L2);
    printList(L);
    printList(L2);
}
int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}
/***********************************
assign(beg,end);
assign(n,elem);
list& operator=(const list &list);

swap(lst); //将lst与本身元素互换
***********************************/