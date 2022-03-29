#include <iostream>
#include <string>
#include <ctime>
using namespace std;
struct Student
{
    string name;
    int score;
};
struct Teacher
{
    string name;
    Student stu[5];
};
void allocate(Teacher *t, int len)
{
    srand((unsigned int)time(NULL));
    string nameSpeed = "ABCDE";
    for (int i = 0; i < len; i++)
    {
        t[i].name = "Teacher_";
        t[i].name += nameSpeed[i];
        for (int j = 0; j < 5; j++)
        {
            t[i].stu[j].name = "Student_";
            t[i].stu[j].name += nameSpeed[j];
            t[i].stu[j].score = rand() % 40 + 61;
        }
    }
}
void Printf(Teacher *t, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << "老师的姓名为：" << t[i].name << endl;
        for (int j = 0; j < 5; j++)
        {
            cout << "\t学生:" << t[i].stu[j].name << "  成绩：" << t[i].stu[j].score << endl;
        }
    }
}
int main()
{
    Teacher t[3];
    int len = sizeof(t) / sizeof(t[0]);
    allocate(t, len);
    Printf(t, len);
    system("pause");
    return 0;
}
/*******************************
学校在做毕设项目，每名老师带领5个学生，总共有3名老师，需求如下
设计学生和老师的结构体，其中在老师的结构体中，有老师姓名和一个存放5名学生的数组作为成员，学生的成员
有姓名、考试分数，创建数组存放3名老师，通过函数给每个老师及所带的学生赋值最终打印出老是数据以及老师
所带的学生的数据
********************************/