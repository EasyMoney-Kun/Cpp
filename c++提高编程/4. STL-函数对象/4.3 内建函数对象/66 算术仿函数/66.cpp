#include <iostream>
using namespace std;
#include <functional>
void test01()
{
    plus<int> pl;
    minus<int> mi;
    multiplies<int> mu;
    divides<int> di;
    modulus<int> mo;
    cout << pl(7, 3) << endl;
    cout << mi(7, 3) << endl;
    cout << mu(7, 3) << endl;
    cout << di(7, 3) << endl;
    cout << mo(7, 3) << endl;
}
void test02()
{
    negate<int> ne;
    cout << ne(10) << endl;
}
int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}
/***********************************
需要引入头文件 #include<functional>

template<class T>T plus<T> //加法仿函数
template<class T>T minus<T> //减法仿函数
template<class T>T multiplies<T> //乘法仿函数
template<class T>T divides<T> //除法仿函数
template<class T>T modulus<T> //取模仿函数
template<class T>T negate<T> //取反仿函数
***********************************/