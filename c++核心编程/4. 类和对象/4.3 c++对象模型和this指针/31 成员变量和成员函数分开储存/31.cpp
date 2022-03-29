#include <iostream>
using namespace std;
// 成员变量 和 成员函数 分开存储的
class Person
{
};
class Person1
{
public:
    int m_A;        // 非静态成员变量 属于类的对象上
    static int m_B; // 静态成员变量 不属于类的对象上
    void func() {}  // 非静态成员函数 不属于类的对象上
    static void func1() {} // 静态成员函数 不属于类的对象上
};
int Person1::m_B = 0;
void test01()
{
    Person p;
    cout << "sizeof(p)=" << sizeof(p) << endl; // c++编译器会给每个空对象也分配一个字节空间，是为了区分空对象占内存的位置
                                               // 每个空对象也因该有独一无二的内存地址
}
void test02()
{
    Person1 p;
    cout << "sizeof(p)=" << sizeof(p) << endl;
}
int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}
/***********************************
在c++中，类内的成员变量和成员函数分开存储
只有非静态成员变量才属于类的对象上
***********************************/