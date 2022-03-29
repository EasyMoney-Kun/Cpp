#include <iostream>
using namespace std;
void func(int &a)
{
    cout << "func(int &a)调用" << endl;
}
void func(const int &a)
{
    cout << "func(const int &a)调用" << endl;
}
// void func(int a,int b = 10)
// {
//     cout << "func(int a,int b=10)调用" << endl;   函数重载碰到函数默认参数
// }
// void func(int a)
// {
//     cout << "func(int a)调用" << endl;
// }
int main()
{
    int a = 10;
    func(a);
    func(10);
    system("pause");
    return 0;
}
/***********************************
函数重载注意事项：
    引用作为重载条件
    函数重载碰到函数默认参数
***********************************/