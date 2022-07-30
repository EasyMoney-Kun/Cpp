#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
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
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i + 1);
    }
    for_each(v1.begin(), v1.end(), Print());
    cout << endl;
    for_each(v2.begin(), v2.end(), Print());
    cout << endl;

    vector<int> vTarget;
    // 目标容器需要提前开辟空间
    vTarget.resize(v1.size() + v2.size());
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    for_each(vTarget.begin(), vTarget.end(), Print());
    cout << endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
merge(iterator beg1,iterator end1,iterator beg2.iterator end2,iterator dest)

容器元素合并，并存储到另一个容器中
两个容器必须是有序的
***********************************/
