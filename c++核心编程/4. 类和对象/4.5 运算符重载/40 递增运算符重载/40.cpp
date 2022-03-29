#include <iostream>
using namespace std;
class MyInterger
{
    friend ostream &operator<<(ostream &cout, const MyInterger &myint);

public:
    MyInterger()
    {
        m_Num = 0;
    }
    // 重载前置++运算符 返回引用是为了一直对一个数据进行递增操作
    MyInterger &operator++()
    {
        m_Num++;
        return *this;
    }
    // 重置后置++运算符 int代表占位参数，可以用于区分前置和后置递增
    MyInterger operator++(int)
    {
        // 先 记录当时结果
        MyInterger temp = *this;
        m_Num++;
        // 返回当时记录的值
        return temp;
    }

private:
    int m_Num;
};
ostream &operator<<(ostream &cout, const MyInterger &myint)
{
    cout << "myint=" << myint.m_Num;
    return cout;
}
void test01()
{
    MyInterger a;
    ++a;
    cout << ++a << endl;
}
void test02()
{
    MyInterger b;
    cout << b++ << endl;
    cout << b << endl;
}
int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}
/***********************************

***********************************/