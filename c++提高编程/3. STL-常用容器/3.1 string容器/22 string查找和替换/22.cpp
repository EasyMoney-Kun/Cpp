#include <iostream>
using namespace std;
void test01()
{
    string str1 = "asdfgdsdgh";
    int pos = str1.find("sd");
    if (pos == -1) // 找不到返回-1
    {
        cout << "未找到字符串" << endl;
    }
    else
    {
        cout << "找到了pos=" << pos << endl;
    }
    // rfind
    pos = str1.rfind("sd");
    cout << pos << endl;
}
void test02()
{
    string str2 = "asafgfdh";
    str2.replace(2, 3, "3232525");
    cout << str2 << endl;
    str2.replace(0, 1, str2);
    cout << str2 << endl;
}
int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}
/***********************************
功能描述：
    查找：查找指定字符串是否存在
    替换：在指定位置替换字符串

函数原型：
int find(const string& str,int pos=0) const; //查找str第一次出现位置，从pos开始查找
int find(const char* s,int pos=0) const; //查找s第一次出现位置，从pos开始查找
int find(const char* s,int pos,int n) const; //从pos位置查找s的前n个字符第一次位置
int find(const char c,int pos=0) const; //查找字符c第一次出现位置

int rfind(const string& str,int pos=npos) const; //查找str最后一次，从pos位置开始查找
int rfind(const char* s,int pos=npos) const; //查找s最后一次出现位置，从pos开始查找
int rfind(const char* s,int pos,int n) const; //从pos查找s的前n个字符最后一次位置
int rfind(const char c,int pos=0) const; //查找字符c最后一次出现的位置

string& replace(int pos,int n,const string& str); //替换从pos开始n个字符为字符串str
string& replace(int pos,int n,const char* s); //替换从pos开始的n个字符为字符串s
***********************************/