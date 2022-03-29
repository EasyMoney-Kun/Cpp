#include <iostream>
#include <string>
using namespace std;
int main()
{
    char str[] = "hello world!";
    cout << "c语言风格:" << str << endl;
    string str2 = "hello world!";//头文件 #incldue<string>
    cout << "c++语言风格:" << str2 << endl;
    system("pause");
    return 0;
}
/******************************
作用：用于表示一窜字符
两种类型:1.c风格 char 变量名[]=" "
        2.c++风格 string 变量名=" "
*******************************/