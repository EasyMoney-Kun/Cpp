#include <iostream>
#include <string>
using namespace std;
int main()
{
    int a;
    cout << "请给a赋值：" << endl;
    cin >> a;
    cout << "a=" << a << endl;
    float b;
    cout << "请给b赋值：" << endl;
    cin >> b;
    cout << "b=" << b << endl;
    char c;
    cout << "请给c赋值：" << endl;
    cin >> c;
    cout << "c=" << c << endl;
    string d;
    cout << "请给d赋值：" << endl;
    cin >> d;
    cout << "d=" << d << endl;
    bool e;
    cout << "请给e赋值：" << endl;
    cin >> e;
    cout << "e=" << e << endl;
    system("pause");
    return 0;
}
/*******************************
作用：用于从键盘中获取数据
语法：cin >> 变量
********************************/