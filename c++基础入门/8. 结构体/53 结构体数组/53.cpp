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
    Student arr[] = {{"张三", 12, 100},
                     {"李四", 13, 99},
                     {"王五", 14, 98}};
    int len = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < len; i++)
    {
        cout << "姓名：" << arr[i].name << "年龄：" << arr[i].age << "成绩：" << arr[i].score << endl;
    }
    system("pause");
    return 0;
}
/*******************************
作用：将自定义的结构体放入数组中方便维护
语法：struct 结构体名 数组名[元素个数]={{}，{}，{}....}
********************************/