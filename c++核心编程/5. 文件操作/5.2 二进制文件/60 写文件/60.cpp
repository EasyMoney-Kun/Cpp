#include <iostream>
using namespace std;
#include <fstream>
// 二进制文件 写文件
class Person
{
public:
    char m_Name[64];
    int m_Age;
};
void test01()
{
    // 1.包含头文件
    // 2.创建流对象
    ofstream ofs;
    // 3.打开文件
    ofs.open("person.txt", ios::out | ios::binary);
    // 4.写文件
    Person p = {"张三", 18};
    ofs.write((const char *)&p, sizeof(Person));
    // 5.关闭文件
    ofs.close();
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
二进制方式写文件主要利用流对象调用成员函数write
函数原型： ostream& write(const char* buffer,int len)
函数解释：字符指针buffer指向内存中的一段存储空间。len是读写的字节数
***********************************/