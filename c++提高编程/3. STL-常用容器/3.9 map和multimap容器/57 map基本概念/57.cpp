#include <iostream>
using namespace std;
#include <map>
void printMap(const map<int, int> &m)
{
    for (map<int, int>::const_iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key=" << (*it).first << " value=" << (*it).second << endl;
    }
}
void test01()
{
    map<int, int> m;
    m.insert(pair<int, int>(1, 111)); //匿名对组
    m.insert(pair<int, int>(4, 132));
    m.insert(pair<int, int>(5, 15));
    m.insert(pair<int, int>(2, 16));
    printMap(m);

    map<int, int> m1(m);
    printMap(m1);

    map<int, int> m2;
    m2 = m;
    printMap(m2);
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
map中所有元素都是pair
pair中第一个元素为key（键值），起到索引作用，第二个元素为value（实值）
所有元素都会根据元素的键值自动排序

本质：map/multimap属于 关联式容器 ，底层结构使用二叉树实现的

优点：可以根据key值快速找到value值

map和multimap区别
map不允许容器中有重复key值元素
multimap允许容器中有重复key值元素

map<T1,T2> mp;
map(const map &map);

赋值
map& operator=(const map&map);
***********************************/