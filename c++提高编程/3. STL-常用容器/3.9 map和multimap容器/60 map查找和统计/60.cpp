#include <iostream>
using namespace std;
#include <map>
void test01()
{
    map<int, int> m1;
    m1.insert(make_pair(1, 10));
    m1.insert(make_pair(3, 30));
    m1.insert(make_pair(2, 20));
    m1.insert(make_pair(4, 40));
    m1.insert(make_pair(7, 40));

    map<int, int>::iterator pos = m1.find(6);
    if (pos != m1.end())
    {
        cout << "找到了元素"
             << "key=" << (*pos).first << "value=" << (*pos).second << endl;
    }
    else
    {
        cout << "未找到" << endl;
    }
    int num = m1.count(1);
    cout << num << endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
find(key)； //查找key是否存在，若存在，返回该键的元素的迭代器；若不存在，返回set.end()
count(key); //统计key的元素个数
***********************************/