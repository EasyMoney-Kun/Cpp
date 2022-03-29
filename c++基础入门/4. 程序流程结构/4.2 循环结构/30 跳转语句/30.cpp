#include <iostream>
using namespace std;
int main()
{
    cout << "1xxxxxxx" << endl;
    cout << "1xxxxxxx" << endl;
    goto FLAG;
    cout << "1xxxxxxx" << endl;
    cout << "1xxxxxxx" << endl;
    FLAG:
    cout << "1xxxxxxx" << endl;
    system("pause");
    return 0;
}
/*******************************
break语句作用：用于跳出选择结构或者循环结构
break使用的时机：1.出现在switch条件语句中，作用是终止case并跳出switch
                2.出现在循环语句中，作用是跳出当前的循环语句
                3.出现在嵌套循环中，跳出最近的内层循环语句中

continue语句作用：在循环语句中，跳过本次循环中余下尚未执行的语句，继续执行下一次循环

goto语句的作用：可以无条件跳转语句
语法：goto 标记;
解释：如果标记的名称存在，执行到goto语句时，会跳转到标记的位置
一般用于跳出多重循环，正常情况下不用
********************************/