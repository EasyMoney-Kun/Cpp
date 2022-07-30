#include <iostream>
using namespace std;
#include <deque>
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
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    PrintDeque(d1);
    if (d1.empty())
    {
        cout << "d1为空" << endl;
    }
    else
    {
        cout << "d1不为空" << endl;
        cout << "d1的大小为：" << d1.size() << endl;
    }
    d1.resize(14,6);
    PrintDeque(d1);
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
功能描述：对deque容器大小进行操作

函数原型：
deque.empty(); //判断容器是否为空
deque.size(); //返回容器中元素的个数
deque.resize(num); //重新指定容器的长度为num,若容器变长，则以默认值填充新位置
                    //如果容器变短，则末尾超出容器长度的元素被删除
deque.resize(num,elem);//重新指定容器的长度为num,若容器变长，则以elem填充新位置
                    //如果容器变短，则末尾超出容器长度的元素被删除

deque没有容量概念
***********************************/