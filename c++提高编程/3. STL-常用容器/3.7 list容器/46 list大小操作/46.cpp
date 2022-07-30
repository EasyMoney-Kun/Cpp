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
    //判断容器是否为空
    if (L.empty())
    {
        cout << "容器为空" << endl;
    }
    else
    {
        cout << "容器不为空" << endl;
        cout << "L元素的个数为：" << L.size() << endl;
    }
    //重新指定大小
    L.resize(10,6);
    printList(L);
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
size();
empty();
resize(num); //变长以默认值填充新位置，变短则末尾超出容器长度的元素被删除
resize(num,elem); //变长以 elem 填充新位置，变短则末尾超出容器长度的元素被删除
***********************************/