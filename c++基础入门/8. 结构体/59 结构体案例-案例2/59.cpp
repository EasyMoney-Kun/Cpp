#include <iostream>
#include <string>
using namespace std;
struct Hero
{
    string name;
    int age;
    string sex;
};
void bubbleSort(Hero *team, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (team[j].age > team[j + 1].age)
            {
                Hero temp = team[j];
                team[j] = team[j + 1];
                team[j + 1] = temp;
            }
        }
    }
}
void Printf(Hero *team, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << team[i].name << "\t" << team[i].age << "\t" << team[i].sex << endl;
    }
}
int main()
{
    Hero team[5] = {{"刘备", 23, "男"},
                    {"关羽", 22, "男"},
                    {"张飞", 20, "男"},
                    {"赵云", 21, "男"},
                    {"貂蝉", 19, "女"}

    };
    int len = sizeof(team) / sizeof(team[0]);
    cout << "排序前：" << endl;
    Printf(team, len);
    bubbleSort(team, len);
    cout << "排序后：" << endl;
    Printf(team, len);
    system("pause");
    return 0;
}
/*******************************
设计一个英雄的结构体，包括成员的姓名，年龄，性别;创建结构体数组，数组存放五位英雄。通过冒泡排序的算法
，讲述组中的英雄按照年龄排序，最终打印排序后的结果
********************************/