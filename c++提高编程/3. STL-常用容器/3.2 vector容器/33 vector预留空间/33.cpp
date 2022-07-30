#include <iostream>
using namespace std;
#include <vector>
void test01()
{
    vector<int> v1;
    int num = 0; //统计内存开辟的次数
    int *p = NULL;
    v1.reserve(99999999);
    for (int i = 0; i < 100000000; i++)
    {
        v1.push_back(i);
        if (p != &v1[0])
        {
            p = &v1[0];
            num++;
        }
    }
    cout << num << endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
功能描述：
减少vector在动态扩展时的扩展次数

函数原型：
reserve(int len); //容器预留len个元素长度，预留位置不初始化，元素不可访问
***********************************/