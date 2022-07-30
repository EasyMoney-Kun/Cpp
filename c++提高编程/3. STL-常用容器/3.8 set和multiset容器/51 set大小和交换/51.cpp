#include <iostream>
using namespace std;
#include <set>
void printSet(const set<int> &s)
{
    for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
void test01()
{
    set<int> s1; //插入用insert
    s1.insert(19);
    s1.insert(139);
    s1.insert(149);
    s1.insert(119);
    s1.insert(199);
    printSet(s1);

    if (s1.empty())
    {
        cout << "s1为空" << endl;
    }
    else
    {
        cout << "s1不为空" << endl;
        cout << "大小为：" << s1.size() << endl;
    }
}
void test02()
{
    cout << "交换前：" << endl;
    set<int> s1;
    s1.insert(19);
    s1.insert(139);
    s1.insert(149);
    s1.insert(119);
    s1.insert(199);
    printSet(s1);
    set<int> s2;
    s2.insert(1);
    s2.insert(4);
    s2.insert(2);
    s2.insert(3);
    printSet(s2);
    cout << "交换后：" << endl;
    s1.swap(s2);
    printSet(s1);
    printSet(s2);
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
swap(st); //交换
***********************************/