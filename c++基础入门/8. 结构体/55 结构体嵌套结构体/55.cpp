#include <iostream>
#include <string>
using namespace std;
struct Student
{
    string name;
    int age;
    int score;
};
struct Teacher
{
    int id;
    string name;
    struct Student s1;
};


using namespace std;
int main()
{
    Student s1={"小刘",13,100};
    Teacher t1={10086,"老刘",{"小刘",13,100}};
    cout << "老师编号：" << t1.id << "老师姓名：" << t1.name << "老师辅导的学生姓名：" << t1.s1.name << "老师辅导的学生年龄：" << t1.s1.age << "老师辅导的学生成绩：" << t1.s1.score << endl;
    system("pause");
    return 0;
}
/*******************************
作用：结构体中的成员可以是另一个结构体
例如：每个老师辅导一个学员，一个老师的结构体中，记录一个学生的结构体
********************************/