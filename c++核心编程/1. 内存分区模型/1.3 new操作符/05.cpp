#include <iostream>
using namespace std;
int *func()
{
    int *a = new int(10);
    return a;
}
void test()
{
    int *arr = new int[10]; // 在堆区利用new开辟一个数组
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i + 100;
    }
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << endl;
    }
    delete[] arr; // 释放堆区数组的时候 要加[]才可以
}
int main()
{

    int *p = func();
    cout << *p << endl;
    delete p;
    cout << *p << endl;
    cout << p << endl;
    test();
    system("pause");
    return 0;
}
/***********************************
c++中用new操作符在堆区中开辟数据
堆区开辟的数据，由程序员手动开辟，手动释放，释放利用操作符 delete
语法：new 数据数据类型
利用new创建的数据，会返回该数据对应的类型的指针
***********************************/