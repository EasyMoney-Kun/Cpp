#include <iostream>
#include <string>
using namespace std;
struct Student
{
    string name;
    int age;
    int score;
};
void Printf(Student *s1)
{

    cout << "姓名：" << s1->name << "年龄：" << s1->age << "成绩：" << s1->score << endl;
    s1->age=29;
}
int main()
{
    Student s1 = {"张三", 19, 100};
    Student *p=&s1;
    Printf(p);
    //Printf(s1);
    cout << "姓名：" << s1.name << "年龄：" << s1.age << "成绩：" << s1.score << endl;
    system("pause");
    return 0;
}
/*******************************
作用：将结构体做参数向函数传递
传递方式：值传递
        地址传递 优点：节省空间，减少内存
                 缺点；原数据容易被修改 要用const修饰使其不能被修改
********************************/