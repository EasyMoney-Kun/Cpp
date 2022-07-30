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
    set<int> s1;
    s1.insert(19);
    s1.insert(139);
    s1.insert(149);
    s1.insert(119);
    s1.insert(199);
    printSet(s1);

    //删除
    s1.erase(s1.begin());
    printSet(s1);
    s1.erase(119);
    printSet(s1);
    s1.clear();
    printSet(s1);
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
inset(elem);

clear();

erase(pos); //删除pos迭代器所指的元素，返回下一个元素的迭代器
erase(beg,end); //删除区间[beg,end)的所有元素，返回下一个元素的迭代器
erase(elem); //删除容器中值为elem的元素
***********************************/