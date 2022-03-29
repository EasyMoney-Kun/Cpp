#include <iostream>
using namespace std;
#include <string>
struct Student
{
    string name;
    int age;
    int score;
} s3; // 定义结构体时顺便创建变量
int main()
{
    // strcut 结构体名 变量名
    struct Student s1;// struct 可以省略
    s1.name = "张三";// .操作符访问成员
    s1.age = 12;
    s1.score = 100;
    cout << "姓名：" << s1.name << "年龄：" << s1.age << "成绩：" << s1.score << endl;

    // struct 结构体名 变量名 ={成员1值，成员2值.....}
    struct Student s2 = {"李四", 13, 99};
    cout << "姓名：" << s2.name << "年龄：" << s2.age << "成绩：" << s2.score << endl;

    s3.name = "王五";
    s3.age = 14;
    s3.score = 98;
    cout << "姓名：" << s3.name << "年龄：" << s3.age << "成绩：" << s3.score << endl;

    system("pause");
    return 0;
}
/*******************************
结构体属于用户自定义的数据类型，允许用户存储不同的数据类型
语法： struct 结构体名 {结构体成员列表};
通过结构体创建变量的方式：1.strcut 结构体名 变量名
                        2.struct 结构体名 变量名 ={成员1值，成员2值.....}
                        3.定义结构体时顺便创建变量
********************************/