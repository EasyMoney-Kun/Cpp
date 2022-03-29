#include <iostream>
using namespace std;
class Person
{
public:
    // Person(int a, int b, int c)
    // {
    //     m_A = a;
    //     m_B = b;
    //     m_C = c;
    // }
    Person(int a, int b, int c) : m_A(a), m_B(b), m_C(c)
    {
    }
    Person() : m_A(40), m_B(50), m_C(60)
    {
    }

    int m_A;
    int m_B;
    int m_C;
};
void test01()
{
    Person p(10, 20, 30);
    Person p1;
    cout << p.m_A << endl;
    cout << p.m_B << endl;
    cout << p.m_C << endl;
    cout << p1.m_A << endl;
    cout << p1.m_B << endl;
    cout << p1.m_C << endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************

***********************************/