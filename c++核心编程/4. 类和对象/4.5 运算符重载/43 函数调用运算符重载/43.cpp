#include <iostream>
using namespace std;
class MyPrint
{
public:
    // 重载函数调用运算符
    void operator()(string test)
    {
        cout << test << endl;
    }
};
class MyAdd
{
public:
    int operator()(int num1, int num2)
    {
        return num1 + num2;
    }
};
void MyPrint01(string test)
{
    cout << test << endl;
}
void test01()
{
    MyPrint p;
    p("hello world"); // 由于使用起来非常类似于函数调用，因此称为仿函数
    MyPrint01("hello world");
}
void test02()
{
    MyAdd add;
    cout << add(10, 20) << endl;
    // 匿名函数对象使用完立马被回收
    cout << MyAdd()(100, 100) << endl;
}
int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}
/***********************************
函数调用运算符（）也可以重载
由于重载后使用的方式非常像函数的调用，因此称为仿函数
仿函数没有固定写法，非常灵活
***********************************/