#include <iostream>
using namespace std;
int main()
{
    bool flag = true;
    cout << flag << endl;
    flag = false;
    cout << flag << endl;
    cout << "bool类型所占字节：" << sizeof(flag) << endl;
    system("pause");
    return 0;
}
/*******************************
作用：布尔类型数据代表真货架的值
bool类型只有两个值：1.true 真（本质是1）
                   2.false 假（本质是0）
bool类型占1个字节大小
********************************/