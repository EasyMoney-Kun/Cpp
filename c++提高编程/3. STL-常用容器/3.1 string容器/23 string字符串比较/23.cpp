#include <iostream>
using namespace std;
void test01()
{
    string str1 = "iello";
    string str2 = "hello";
    if (str1.compare(str2) == 0)
    {
        cout << "相等" << endl;
    }
    else if (str1.compare(str2) > 0)
    {
        cout << "str1>str2" << endl;
    }
    else{
        cout<<"str1<str2"<<endl;
    }
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
功能描述：
字符串之间的比较

比较方式：
字符串比较是按字符的ascii进行比较
= 返回0
> 返回1
< 返回-1

函数原型
int compare(const string &s) const; //与字符串s比较
int compare(const char* s) const; //与字符串s比较
***********************************/