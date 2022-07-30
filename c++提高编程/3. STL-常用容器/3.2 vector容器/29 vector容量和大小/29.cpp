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
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    PrintVector(v1);
    if (v1.empty()) //为真 代表容器为空
    {
        cout << "v1为空" << endl;
    }
    else
    {
        cout << "v1不为空" << endl;
        cout << "v1的容量为：" << v1.capacity() << endl;
        cout << "v1的大小为：" << v1.size() << endl;
    }
    v1.resize(17); //重新指定容器的长度为num，若容器变长，则以默认值填充新位置
    PrintVector(v1);
    cout << "容量:" << v1.capacity() << endl;
    v1.resize(10); //如果容器变短，则末尾超出容器长度的元素被删除
    PrintVector(v1);
    cout << "容量:" << v1.capacity() << endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
功能描述：对vector容器的容量和大小操作

函数原型:
empty(); //判断容器是否为空
capacity(); //容器的容量
size(); //返回容器中元素的个数
resize(int num); //重新指定容器的长度为num，若容器变长，则以默认值填充新位置
                  //如果容器变短，则末尾超出容器长度的元素被删除
resize(int num,elem); //重新指定容器的长度为num，若容器变长，则以elem值填充新位置
                      //如果容器变短，则末尾超出容器长度的元素被删除
***********************************/