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

    set<int> s2(s1);
    printSet(s2);

    set<int> s3;
    s3 = s1;
    printSet(s3);
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
简介:所有元素在插入时都会自动被排序

本质：set/multiset属于关联式容器，底层结构是用二叉树实现的

set和multiset区别
    set不允许容器中有重复的元素
    multiset允许容器中有重复的元素
构造：
set<T> st;
set(const set &st);
赋值：
set& operator=(const set &st);
***********************************/