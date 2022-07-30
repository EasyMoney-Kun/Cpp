#include <iostream>
using namespace std;
#include <string>
void test01()
{
    string str = "asdffgh";
    string substr = str.substr(1, 2);
    cout << "substr=" << substr << endl;
}
// 实用操作
void test02()
{
    string str = "2967099002@qq.com";
    int pos = str.find("@");
    string substr = str.substr(0, pos);
    cout << "substr=" << substr << endl;
}
int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}
/***********************************
功能描述：从字符串中获取想要的子串

函数原型：
string substr(int pos=0,int n=npos) const; //返回由pos开始的n个字符组成的字符串
***********************************/