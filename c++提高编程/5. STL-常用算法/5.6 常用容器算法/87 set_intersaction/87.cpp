#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <ctime>
class Print
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }
};
void test01()
{
    srand((unsigned int)time(NULL));
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i + 5);
    }
    // random_shuffle(v1.begin(), v1.end()); 必须升序排列
    vector<int> vTarget;
    // 目标容器需要提前开辟空间
    // 最特殊情况 大容器包含小容器 开辟空间 取小容器的size即可
    vTarget.resize(min(v1.size(), v2.size()));
    vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    for_each(vTarget.begin(), vTarget.end(), Print());
    cout << endl;
    for_each(vTarget.begin(), itEnd, Print());
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
求交集的两个集合必须的有序序列
目标容器开辟空间需要从两个容器中取最小值
set_intersection 返回值即是交集中最后一个元素的位置
***********************************/
