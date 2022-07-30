#include <iostream>
using namespace std;
#include <stack>
void test01()
{
    stack<int> s;
    for (int i = 1; i < 4; i++)
    {
        s.push(i);
    }
    cout << "栈的大小：" << s.size() << endl;
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    cout << "栈的大小：" << s.size() << endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
栈

构造函数：
stack<T> stk; //普通构造
stack(const stack &stk); //默认构造

赋值操作：
stack& operator=(const stack &stk); //重载等号

数据存取：
push(elem); //向栈顶添加元素
pop(); //从栈顶移除第一个元素
top(); //返回栈顶元素

大小操作：
empty();
size();
***********************************/