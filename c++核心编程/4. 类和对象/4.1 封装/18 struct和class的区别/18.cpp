#include <iostream>
using namespace std;
class c1
{
    int m_a;
};
struct c2
{
    int m_a;
};
int main()
{
    c1 c1;
    // 默认权限为私有 c1.m_a;
    c2 c2;
    c2.m_a = 1000;
    system("pause");
    return 0;
}
/***********************************
在c++中struct和class的唯一区别就在于默认的访问权限不同
区别：
    struct  默认权限为公共
    class   默认权限为私有
***********************************/