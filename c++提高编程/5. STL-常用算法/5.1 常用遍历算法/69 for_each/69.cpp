#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
void Print(int val) //普通函数
{
    cout << val << " ";
}
class MyPrint //仿函数
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }
};
void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), Print);
    cout << endl;
    for_each(v.begin(), v.end(), MyPrint());
    cout << endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
算法主要是由头文件<algorithem> <functional> <numeric>
<algorithem>是所有STL文件中最大的一个，范围涉及到比较、交换、查找、遍历操作、复制、修改
<numeric>体积很小，只包括几个在序列上面进行简单的数学运算的模板函数
<functional>定义了一些模板类，用以声明函数对象

for_each 遍历容器
***********************************/