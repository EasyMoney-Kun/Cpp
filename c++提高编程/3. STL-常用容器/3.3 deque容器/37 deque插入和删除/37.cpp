#include <iostream>
using namespace std;
#include <deque>
void PrintDeque(const deque<int> &d)
{
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) //只读迭代器
    {
        cout << *it << " ";
    }
    cout << endl;
}
void test01()
{
    deque<int> d1;
    //尾插
    d1.push_back(10);
    d1.push_back(20);
    //头插
    d1.push_front(100);
    d1.push_front(200);
    PrintDeque(d1);
    //尾删和头删
    d1.pop_back();
    d1.pop_front();
    PrintDeque(d1);
    // insert插入
    d1.insert(d1.begin(), 1000);
    PrintDeque(d1);
    d1.insert(d1.begin(), 6, 6);
    PrintDeque(d1);
    deque<int> d2;
    for (int i = 0; i < 10; i++)
    {
        d2.push_back(i);
    }
    d1.insert(d1.begin(), d2.begin(), d2.end()); //在pos位置插入[beg,end]区间的数据，无返回值
    PrintDeque(d1);
    d1.erase(d1.begin());
    PrintDeque(d1);
    d1.erase(d1.begin(), d1.begin() + 9);
    PrintDeque(d1);
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
功能描述：向的确容器中插入和删除数据

函数原型：
两端插入操作：
push_back(elem); //尾插
push_front(elem); //头插
pop_back(elem); //尾删
pop_front(elem); //尾插
指定位置操作：
insert(pos,elem); //在pos位置插入一个elem元素的拷贝，返回新数据的位置
insert(pos,n,elem); //在pos位置插入n个elem数据，无返回值
insert(pos,beg,end); //在pos位置插入[beg,end]区间的数据，无返回值
clear(); //清空容器的所有数据
erase(beg,end); //删除[beg,end)区间数据，返回下一个数据的位置
erase(pos); //删除pos位置的数据，返回下一个数据的位置
***********************************/