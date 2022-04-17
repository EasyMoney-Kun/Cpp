#include <iostream>
using namespace std;
#include <fstream>
#include <string>
void test01()
{
    // 1.包含头文件

    // 2.创建流对象
    ifstream ifs;

    // 3.打开文件并判断是否打开成功
    ifs.open("../58 写文件/test.txt", ios::in);
    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }
    // 4.读数据
    // 第一种
    char buf[1024] = {0};
    while (ifs >> buf)
    {
        cout << buf << endl;
    }
    // 第二种
    char buf1[1024] = {0};
    while (ifs.getline(buf1, sizeof(buf1)))
    {
        cout << buf1 << endl;
    }
    // 第三种
    string buf2;
    while (getline(ifs, buf2))
    {
        cout << buf2 << endl;
    }
    // 第四种
    char c;
    while ((c = ifs.get()) != EOF)
    {
        cout << c;
    }
    ifs.close();
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
读文件与写文件类似，但是读取方式相对比较多

读文件步骤：
    1.包含头文件
    #include<fstream>
    2.创建流对象
    ifstream ifs
    3.打开文件并判断文件是否打开成功
    ifs.open("文件路径",打开方式)
    4.读数据
    四种方式读取
    5.关闭文件
    ifs.close()
***********************************/