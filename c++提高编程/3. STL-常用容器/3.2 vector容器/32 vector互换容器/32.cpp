#include <iostream>
using namespace std;
#include <vector>
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
    cout << "交换前：" << endl;
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    PrintVector(v1);
    vector<int> v2;
    for (int i = 9; i >= 0; i--)
    {
        v2.push_back(i);
    }
    PrintVector(v2);
    //交换
    cout << "交换后：" << endl;
    v1.swap(v2);
    PrintVector(v1);
    PrintVector(v2);
}
void test02() // 实际用途：巧用swap可以收缩内存空间
{
    vector<int> v;
    for (int i = 0; i < 10000; i++)
    {
        v.push_back(i);
    }
    cout << "v的容量为：" << v.capacity() << endl;
    cout << "v的大小为：" << v.size() << endl;
    //重新指定大小后，与容量比非常小，造成空间浪费
    cout << "大小缩小：" << endl;
    v.resize(3);
    cout << "v的容量为：" << v.capacity() << endl;
    cout << "v的大小为：" << v.size() << endl;
    //巧用swap收缩内存
    cout << "swap收缩内存：" << endl;
    vector<int>(v).swap(v);
    cout << "v的容量为：" << v.capacity() << endl;
    cout << "v的大小为：" << v.size() << endl;
}
int main()
{
    // test01();
    test02();
    system("pause");
    return 0;
}
/***********************************
功能描述：实现两个容器之间的互换

函数原型：
swap(vec); //将vec与本身的元素互换
***********************************/