#include <iostream>
using namespace std;
#include <vector>
#include <numeric>
class Person
{
public:
    Person &operator+(Person &first)
    {
        this->age = this->age + first.age;
        return *this;
    }
    int age = 1;
};
void test01()
{
    vector<Person> v;
    for (int i = 0; i < 100; i++)
    {
        Person p;
        v.push_back(p);
    }
    Person p1 = {0}; //p1为初始值
    Person p2;
    p2 = accumulate(v.begin(), v.end(), p1);
    cout << p2.age << endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
算术生成算法属于小型算法，使用时包含的头文件为 #include<numeric>

accumulate
计算区间内容器元素总和
***********************************/