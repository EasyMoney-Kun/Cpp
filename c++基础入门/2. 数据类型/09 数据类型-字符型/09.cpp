#include <iostream>
using namespace std;
int main()
{
    char ch = 'a';
    cout << ch << endl;
    cout << (int)ch << endl;
    cout << int(ch) << endl;
    cout << "ch所占内存大小:" << sizeof(ch) << endl;
    ch = 65; //可以直接用ASCIi码给字符型变量赋值
    cout << ch << endl;
    system("pause");
    return 0;
}
/**************************************
作用：字符型变量用于显示单个字符
语法：char ch='a';
注意：1.在显示字符型变量时，用单引号括起来，不要用双引号
      2.单引号里只能有一个字符，不能有字符串
c和c++里面字符型变量只占一个字节
字符型变量并不是把字符本身放到内存中去储存，而是将对应的ASCII编码放到储存单元中
***************************************/
