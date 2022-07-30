#include <iostream>
using namespace std;
class MyAdd
{
public:
    int operator()(int v1, int v2)
    {
        return v1 + v2;
    }
};
class MyPrint
{
public:
    void operator()(string test)
    {
        cout << test << endl;
        count++;
    }
    int count = 0;
};
// 函数对象在使用时，可以像普通函数那样调用，可以有参数，也可以有返回值
void test01()
{
    MyAdd myadd;
    cout << myadd(1, 1) << endl;
}
// 函数对象超出普通函数的概念，函数对象可以有自己的状态
void test02()
{
    MyPrint myprint;
    myprint("hello");
    myprint("hello");
    myprint("hello");
    myprint("hello");
    cout << "被调用的次数为：" << myprint.count << endl;
}
// 函数对象可以作为参数传递
void doPrint(MyPrint &mp, string test)
{
    mp(test);
}
void test03()
{
    MyPrint myprint;
    doPrint(myprint, "hello,world!");
}
int main()
{
    test01();
    test02();
    test03();
    system("pause");
    return 0;
}
/***********************************
概念：
重载函数调用操作符的类，其对象常称为函数对象
函数对象使用重载的()时，行为类似函数调用，也叫仿函数

本质：
函数对象（仿函数）是一个类，不是一个函数

特点：
函数对象在使用时，可以像普通函数那样调用，可以有参数，也可以有返回值
函数对象超出普通函数的概念，函数对象可以有自己的状态
函数对象可以作为参数传递
***********************************/