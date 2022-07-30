#include <iostream>
using namespace std;
#include <vector>
void PrintVector1(vector<int> &v) //返回索引idx所指的数据
{
    cout << "at(int idx):";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << " ";
    }
    cout << endl;
}
void PrintVector2(vector<int> &v)
{
    cout << "operator[]:";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " "; //返回索引idx所指的数据
    }
    cout << endl;
}

void test01()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    PrintVector1(v1);
    PrintVector2(v1);
    cout << "front:" << v1.front() << endl;
    cout << "back:" << v1.back() << endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
功能描述：对vector中的数据的存取操作

函数原型：
at(int idx); //返回索引idx所指的数据
operator[]; //返回索引idx所指的数据
front(); //返回容器中第一个数据元素
back(); //返回容器中最后一个数据元素
***********************************/