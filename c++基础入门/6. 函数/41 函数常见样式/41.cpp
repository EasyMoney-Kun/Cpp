#include <iostream>
using namespace std;
void test01() //无参无返
{
    cout << "this is test01" << endl;
}
void test02(int num) //有参无返
{
    cout << "this is test0" << num << endl;
}
int test03() //无参有返
{
    cout << "this is test0";
    return 3;
}
int test04(int num)//有参有返
{
    return num;
}
int main()
{
    test01();
    int a = 2;
    test02(a);
    cout << test03() << endl;
    int b = 4;
    cout << "this is test0" << test04(b) << endl;

    system("pause");
    return 0;
}
/*******************************
常见的函数样式有4种：
1.无参无返
2.有参无返
3.无参有返
4.有参有返
********************************/