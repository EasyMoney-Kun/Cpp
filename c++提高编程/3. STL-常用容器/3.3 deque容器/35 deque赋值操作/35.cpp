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
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    PrintDeque(d1);
    deque<int> d2; //重载等号操作符
    d2 = d1;
    PrintDeque(d2);
    deque<int> d3; //将[beg,end)区间中的数据拷贝赋值给本身
    d3.assign(d1.begin(), d1.end());
    PrintDeque(d3);
    deque<int> d4; //将n个elem拷贝赋值给本身
    d4.assign(6, 6);
    PrintDeque(d4);
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
功能描述：
deque容器进行赋值

函数原型：
deque& operator=(const deque &deq); //重载等号操作符
assign(beg,end); //将[beg,end)区间中的数据拷贝赋值给本身
assign(n,elem); //将n个elem拷贝赋值给本身
***********************************/