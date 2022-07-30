#include <iostream>
using namespace std;
#include <vector>
void PrintVector(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
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
    PrintVector(v1);
    vector<int> v2; //重载等号运算符
    v2 = v1;
    PrintVector(v2);
    vector<int> v3; //将[beg,end]区间中的数据拷贝赋值给本身
    v3.assign(v1.begin(), v1.end());
    PrintVector(v3);
    vector<int> v4; //将n个elem拷贝赋值给本身
    v4.assign(6, 6);
    PrintVector(v4);
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
功能描述：给vector容器赋值

函数原型：
vector& operator=(const vector &vec); //重载等号运算符
assign(beg,end); //将[beg,end)区间中的数据拷贝赋值给本身
assign(n,elem); //将n个elem拷贝赋值给本身
***********************************/