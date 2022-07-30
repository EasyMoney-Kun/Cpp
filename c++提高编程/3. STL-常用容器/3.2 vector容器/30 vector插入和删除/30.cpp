#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
void PrintVector(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
void test01()
{
    vector<int> v1;
    //尾插
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    //遍历
    PrintVector(v1);
    //尾删
    v1.pop_back();
    PrintVector(v1);
    //迭代器指向位置pos插入元素elem
    v1.insert(v1.begin(), 100);
    PrintVector(v1);
    //迭代器指向位置pos插入count个元素elem
    v1.insert(v1.begin() + 1, 6, 6);
    PrintVector(v1);
    //删除迭代器指向的元素
    v1.erase(v1.begin());
    PrintVector(v1);
    //删除迭代器从start到end之间的元素
    v1.erase(v1.begin(), v1.begin() + 6);
    // v1.erase(v1.begin(), v1.end()); 删除全部元素
    PrintVector(v1);
    //删除容器所有元素
    v1.clear();
    PrintVector(v1);
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
功能描述：
对vector容器进行插入和删除操作

函数原型：
push_back(elem); //尾部插入元素elem
pop_back(); //删除最后一个元素
insert(const_iterator pos, elem); //迭代器指向位置pos插入元素elem
insert(const_iterator pos,int count,else); //迭代器指向位置pos插入count个元素elem
erase(const_iterator pos); //删除迭代器指向的元素
erase(const_iterator); //删除迭代器从start到end之间的元素
clear(); //删除容器中所有元素
***********************************/