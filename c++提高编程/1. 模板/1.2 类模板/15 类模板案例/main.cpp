#include <iostream>
using namespace std;
#include <string>
#include "MyArray.hpp"

template <class T>
void Print(MyArray<T> arr)
{
    for (int i = 0; i < arr.getSize(); i++)
    {
        cout << arr[i] << endl;
    }
}
void test01()
{
    MyArray<int> arr1(5);
    for (int i = 0; i < 5; i++)
    {
        arr1.Push_Back(i);
    }
    Print(arr1);
    cout << arr1.getSize();
    arr1.Pop_Back();
    cout << arr1.getSize();
    Print(arr1);
}
// 自定义数据类型
class Person
{
public:
    Person(){};
    Person(string name, int age)
    {
        this->m_Age = age;
        this->m_Name = name;
    }
    string m_Name;
    int m_Age;
};
void PrintPerson(MyArray<Person> arr)
{
    for (int i = 0; i < arr.getSize(); i++)
    {
        cout << arr[i].m_Name << "\t" << arr[i].m_Age << endl;
    }
}
void test02()
{
    MyArray<Person> person(10);
    Person p1("aa", 10);
    Person p2("bb", 11);
    Person p3("cc", 12);
    person.Push_Back(p1);
    person.Push_Back(p2);
    person.Push_Back(p3);
    PrintPerson(person);
    cout << person.getCapacity() << endl;
    cout << person.getSize();
}
int main()
{
    // test01();
    test02();
    system("pause");
    return 0;
}
/***********************************
案例描述：
    实现一个通用的数组类，要去如下：
        可以对内置数据类型以及自定义数据类型的数据进行存储
        将数组的数据存储到堆区
        构造函数中可以传入数组的容量
        提供对应的拷贝构造函数以及operator=防止浅拷贝的问题
        提供尾插法和尾删法对数组中的数据进行增加和删除
        可以通过下标的方式访问数组中的元素
        可以获取数组中当前元素的个数和数组的容量
***********************************/