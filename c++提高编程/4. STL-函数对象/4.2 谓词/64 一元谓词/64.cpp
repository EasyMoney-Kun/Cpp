#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class GreaterFive
{
public:
    bool operator()(int val)
    {
        return val > 5;
    }
};
class paixu
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};
void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    //GreaterFive() 为匿名对象
    vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
    cout << *it << endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
概念：
返回bool类型的仿函数称为谓词
如果operator()接受一个参数，那么叫做一元谓词
如果operator()接受两个参数，那么叫做二元谓词
***********************************/