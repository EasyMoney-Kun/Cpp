#include <iostream>
#include <string>
using namespace std;
struct Student
{
    string name;
    int age;
    int score;
};
int main()
{
    Student s1 = {"张三", 12, 100};
    Student *p = &s1;
    cout << "姓名：" << s1.name << "年龄：" << s1.age << "成绩：" << s1.score << endl;
    cout << "姓名：" << p->name << "年龄：" << p->age << "成绩：" << p->score << endl;

    system("pause");
    return 0;
}
/*******************************
作用：通过指针访问结构体中的成员
利用操作符->可以通过结构体指针访问结构体属性
********************************/