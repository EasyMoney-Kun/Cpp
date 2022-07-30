#include <iostream>
using namespace std;
#include <set>
void test01()
{
    set<int> s1;
    s1.insert(19);
    s1.insert(139);
    s1.insert(149);
    s1.insert(119);
    s1.insert(199);
    for (multiset<int>::iterator it = s1.begin(); it != s1.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    set<int>::iterator pos = s1.find(199);
    if (pos != s1.end())
    {
        cout << "找到元素：" << *pos << endl;
    }
    else
    {
        cout << *pos << endl;
    }
    int num = s1.count(19);
    cout << num << endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
find(key); //查找key是否存在，返回该键的元素迭代器；若不存在，返回set.end();
count(key); //统计key的元素的个数
***********************************/