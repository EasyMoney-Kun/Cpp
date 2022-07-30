#include <iostream>
using namespace std;
#include <deque>
void test01()
{
    deque<int> d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_back(100);
    d1.push_back(200);
    for (int i = 0; i < d1.size(); i++)
    {
        cout << d1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < d1.size(); i++)
    {
        cout << d1.at(i) << " ";
    }
    cout << endl;
    cout << "back:" << d1.back() << endl;
    cout << "front:" << d1.front() << endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
功能描述：对deque中的数据的存取操作

函数原型：
at(int idx); //返回索引idx所指的数据
operator[]; //返回索引idx所指的数据
front(); //返回容器中第一个数据元素
back(); //返回容器中最后一个数据元素
***********************************/