#include <iostream>
using namespace std;
int main()
{
    cout << "给电影进行评价，请输入你的分数：";
    int score;
    cin >> score;
    cout << "您输入的分数为：" << score << endl;
    switch (score)
    {
    case 10:
        cout << "您认为是经典电影" << endl;
        break;//不用break 会继续执行下一个分支
    case 9:
        cout << "您认为是经典电影" << endl;
        break;
    case 8:
        cout << "您认为是经典电影" << endl;
        break;
    case 7:
        cout << "您认为电影一般般" << endl;
        break;
    case 6:
        cout << "您认为电影一般般" << endl;
        break;
    case 5:
        cout << "您认为电影一般般" << endl;
        break;
    case 4:
        cout << "您认为电影一般般" << endl;
        break;
    case 3:
        cout << "您认为电影垃圾" << endl;
        break;
    case 2:
        cout << "您认为电影垃圾" << endl;
        break;
    case 1:
        cout << "您认为电影垃圾" << endl;
        break;
    case 0:
        cout << "您认为电影垃圾" << endl;
        break;
    }

    system("pause");
    return 0;
}
/*******************************
作用：执行多条件分支语句
if和switch的区别：
switch的缺点，判断时候只能是整型或者字符型，不可以是一个区间
switch的优点，结构清晰，执行效率高
********************************/