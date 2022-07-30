#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class MyPrint //仿函数
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }
};
class Transform
{
public:
    int operator()(int val)
    {
        return val + 100;
    }
};
void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    vector<int> vTarget;
    vTarget.resize(v.size()); //目标容器需要提前开辟空间

    transform(v.begin(), v.end(), vTarget.begin(), Transform());
    for_each(v.begin(), v.end(), MyPrint());
    cout << endl;
    for_each(vTarget.begin(), vTarget.end(), MyPrint());
    cout << endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
功能描述：
搬运一个容器到另一个容器中

transform(iterator beg1,iterator end1,iterator beg2,_func)

***********************************/