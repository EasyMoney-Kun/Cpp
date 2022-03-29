#include <iostream>
using namespace std;
class Person
{
public:
    Person()
    {
        cout << "Person无参函数的调用" << endl;
    }
    Person(int a)
    {
        age = a;
        cout << "Person有参构造函数的调用" << endl;
    }
    Person(const Person &p)
    {
        cout << "Person拷贝构造函数调用" << endl;
        age = p.age;
    }
    ~Person()
    {
        cout << "Person析构函数的调用" << endl;
    }
    int age;
};
void test01()
{
    // 括号法
    Person p;
    Person p1(10);
    Person p2(p1);
    cout << "p1的年龄为：" << p1.age << endl;
    cout << "p2的年龄为：" << p2.age << endl;
    // 调用默认构造函数时候不要加()
    // Person p(); 编译器会认为是函数的声明，不会认为在创建对象

    // 显示法
    Person p3;
    Person p4 = Person(20);
    Person p5 = Person(p4);
    cout << "p4的年龄为：" << p4.age << endl;
    cout << "p5的年龄为：" << p5.age << endl;
    Person(10); // 匿名对象 特点：当前执行结束后，系统会立即回收掉匿名对象
    cout << "对象被回收" << endl;
   // Person(p4); // 不要利用拷贝构造函数 初始化匿名对象 编译器会认为 Person (p3) == Person p3;
   
    // 隐式转换法
    Person p6 = 30;
    Person p7 = p6; // 相当于写了 Person p7 = Person(p6)
    cout << "p6的年龄为：" << p6.age << endl;
    cout << "p7的年龄为：" << p7.age << endl;

}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
两种分类方式：
    按参数分：有参构造和无参构造（默认构造）
    按类型分：普通构造和拷贝构造
三种调用方式：
    括号法
    显示法
    隐式转换法
***********************************/