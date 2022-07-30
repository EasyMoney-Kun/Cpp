#include <iostream>
using namespace std;
#include <string>
void test01()
{
    string s1; //默认构造
    const char *str = "hello world";
    string s2(str);
    cout << "s2=" << s2 << endl; //使用字符串初始化
    string s3(s2);
    cout << "s3=" << s3 << endl;
    string s4(9, 'b');
    cout << "s4=" << s4 << endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/*************************
本质：string是c++风格的字符串，而string本质上是一个类

string和char*区别：
    插入char* 是一个指针
    string是一个类，类内部封装了char* ，管理这个字符串，是一个char*型的容器
    特点：string内部封装了很多成员方法
    例如：查找find，拷贝copy，删除delete替换replace，插入insert
    string管理char*所分配的内存，不用担心复制越界和取值越界等，由类内部负责

string构造函数原型：
    string(); //创建一个空的字符串 例如;string str;
    string(const char* s) //使用字符串s初始化
    string(const string& str) //使用一个string对象初始化另一个string对象
    string(int n,char c); //使用n个字符c初始化
*************************/