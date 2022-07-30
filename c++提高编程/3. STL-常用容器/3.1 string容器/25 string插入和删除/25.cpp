#include <iostream>
using namespace std;
void test01()
{
    string str = "hello";
    str.insert(1, "www");
    cout << str << endl;
    str.erase(1, 3);
    cout << str << endl;
    str.insert(1, 6, '6');
    cout << str << endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
功能描述：对string字符串进行插入和删除字符操作

函数原型：
string& insert(int pos,const char* s); //插入字符串
string& insert(int pos,const string& str); //插入字符串
string& insert(int pos,int n,char c); //在指定位置插入n个字符c
string& erase(int pos,int n =npos); //删除从pos开始的n个字符
***********************************/