#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    // 如果是无序序列，结果未知
    // 容器必须是有序的序列
    bool ret = binary_search(v.begin(), v.end(), 19);
    if (ret)
        cout << "找到了" << endl;
    else
        cout << "未找到" << endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
bool binary_search(beg,end,value)
查到返回true 否则false
在无序序列中不可用
***********************************/
