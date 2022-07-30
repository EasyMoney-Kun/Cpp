#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
void test01()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(12);
    v.push_back(1);
    v.push_back(1);
    v.push_back(14);
    v.push_back(13);
    vector<int>::iterator it = adjacent_find(v.begin(), v.end());
    if (it == v.end())
    {
        cout << "未找到相邻重复元素" << endl;
    }
    else
    {
        cout << "找到了：" << *it << endl;
    }
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
查找相邻的重复元素

查找相邻的重复元素并返回相邻元素的第一个位置的迭代器
***********************************/