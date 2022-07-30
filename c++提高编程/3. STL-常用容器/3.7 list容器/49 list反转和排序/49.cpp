#include <iostream>
using namespace std;
#include <list>
void printList(const list<int> &L)
{
    for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
bool myCompare(int v1, int v2)
{
    //降序 就让第一个数大于第二个数
    return v1 > v2;
}
void test01()
{
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(70);
    L1.push_back(30);
    L1.push_back(40);
    cout << "反转前：" << endl;
    printList(L1);
    cout << "反转后：" << endl;
    L1.reverse();
    printList(L1);
}
void test02()
{
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(70);
    L1.push_back(30);
    L1.push_back(40);
    cout << "排序前：" << endl;
    printList(L1);
    cout << "排序后：" << endl;
    //所有不支持随机访问迭代器的容器，不可以用标准算法
    //不支持随机访问迭代器的容器，内部会提供对应一些算法
    // sort(L1.begin(),L1.end())
    L1.sort();
    printList(L1);
    L1.sort(myCompare);
    printList(L1);
}
int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}
/***********************************
reverse(); //反转
sort(); //链表排序
***********************************/