#include <iostream>
using namespace std;
struct Student
{
    string name;
    int age;
    int score;
};
void Printf(const Student *s1)// 加入const后,一旦有修改的操作就会报错，可以防止我们的误操作
{

    cout << "姓名：" << s1->name << "年龄：" << s1->age << "成绩：" << s1->score << endl;
    //s1->age = 29; 
}
int main()
{
    Student s1 = {"张三", 19, 100};
    Student *p = &s1;
    Printf(p);
    // Printf(s1);
    cout << "姓名：" << s1.name << "年龄：" << s1.age << "成绩：" << s1.score << endl;
    system("pause");
    return 0;
}
/*******************************
********************************/