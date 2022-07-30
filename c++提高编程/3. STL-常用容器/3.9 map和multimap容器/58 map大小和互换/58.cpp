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
    m.insert(pair<int, int>(1, 111));
    m.insert(pair<int, int>(4, 132));
    m.insert(pair<int, int>(5, 15));
    m.insert(pair<int, int>(2, 16));
    if (m.empty())
    {
        cout << "空" << endl;
    }
    else
    {
        cout << "不为空"
             << " "
             << "大小为：" << m.size() << endl;
    }
}
void test02()
{
    cout << "交换前：" << endl;
    map<int, int> m1;
    m1.insert(pair<int, int>(1, 111));
    m1.insert(pair<int, int>(4, 132));
    m1.insert(pair<int, int>(5, 15));
    m1.insert(pair<int, int>(2, 16));

    map<int, int> m2;
    m2.insert(pair<int, int>(1, 111));
    m2.insert(pair<int, int>(5, 132));
    m2.insert(pair<int, int>(4, 15));
    m2.insert(pair<int, int>(9, 16));
    printMap(m1);
    cout << "------------" << endl;
    printMap(m2);

    cout << "交换后：" << endl;
    m1.swap(m2);
    printMap(m1);
    cout << "------------" << endl;
    printMap(m2);
}
int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}
/***********************************
size();
empty();
swap();
***********************************/