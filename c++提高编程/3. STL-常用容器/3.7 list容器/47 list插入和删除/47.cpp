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
    list<int> L;
    //尾插
    L.push_back(10);
    L.push_back(20);
    L.push_back(30);

    //头插
    L.push_front(1);
    L.push_front(2);
    L.push_front(3);
    printList(L);

    //尾删和头删
    L.pop_back();
    L.pop_front();
    printList(L);

    // insert插入
    L.insert(L.begin(), 6, 6);
    printList(L);

    // remove
    L.remove(6);
    printList(L);

    // clear()
    L.clear();
    printList(L);
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
push_back(elem); //尾插
pop_back();
push_front(elem);
pop_front();

insert(pos,elem);
insert(pos,n,elem);
insert(pos,beg,end); //在pos位置插入[beg,end)区间的数据

clear();

erase(beg,end);
erase(pos);

remove(elem); //删除容器中所有与elem值匹配的元素
***********************************/