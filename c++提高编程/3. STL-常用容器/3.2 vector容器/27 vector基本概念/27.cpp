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
    vector<int> v1; //默认构造 无参构造
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    PrintVector(v1);
    vector<int> v2(v1.begin() + 1, v1.end() - 1); //将v[begin(),end()]区间中的元素拷贝给本身
    PrintVector(v2);
    vector<int> v3(v1); //拷贝构造函数
    PrintVector(v3);
    vector<int> v4(6, 6);
    PrintVector(v4);
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
功能：vector数据结构和数组类似，称为单端数组

vector与普通数组区别：不同之处在于数组是静态空间，而vector可以动态扩展
动态扩展：并不是在原有空间之后接新空间，而是找更大的内存空间，然后将原数据拷贝到新空间，释放原空间
vector容器的迭代器是支持随机访问的迭代器

vector构造函数
vector<T> v; //采用模板实现类实现，默认构造函数
vector(v.begin(),v.end()) //将v[begin(),end())区间中的元素拷贝给本身
vector(n,elem) //构造函数将n个elem拷贝给本身
vector(const vector &vec) //拷贝构造函数
***********************************/