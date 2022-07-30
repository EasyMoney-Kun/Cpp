#include <iostream>
using namespace std;
#include <list>
void test01()
{
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    // L1[0] 不可以用[]访问list容器中的元素
    // L1.at(0) 不可以用at方式访问list容器中的元素
    //原因是list本质链表，不是用连续性线性空间存储数据，迭代器也是不支持随机访问的
    cout << "第一个元素为：" << L1.front() << endl;
    cout << "最后一个元素为：" << L1.back() << endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
front(); //返回最后一个元素
back(); //返回最后一个元素
***********************************/