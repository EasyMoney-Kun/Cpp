#include <iostream>
using namespace std;
#include <deque>
#include <algorithm>
void PrintDeque(const deque<int> &d)
{
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) //只读迭代器
    {
        cout << *it << " ";
    }
    cout << endl;
}
void test01()
{
    deque<int> d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_back(1400);
    d1.push_back(24300);
    d1.push_back(1200);
    d1.push_back(200);
    d1.push_back(1100);
    d1.push_back(2003);
    d1.push_back(100);
    d1.push_back(200);
    PrintDeque(d1);
    sort(d1.begin()+1, d1.end()-1);
    PrintDeque(d1);
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
功能描述：利用算法实现对deque容器排序
算法：sort(iterator beg,iterator end) //对beg和end区间内元素进行排序
对于支持随机访问的迭代器的容器，都可以利用sort算法直接对其进行排序
vector容器也可以利用sort进行排序
***********************************/