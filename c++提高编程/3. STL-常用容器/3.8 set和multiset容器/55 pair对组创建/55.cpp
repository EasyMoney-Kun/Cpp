#include <iostream>
using namespace std;
#include <string>
void test01()
{
    pair<string, int> p("giao", 20);
    cout << p.first << " " << p.second << endl;

    pair<string, int> p1 = make_pair("lk", 20);
    cout << p1.first << " " << p1.second << endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
pair<type,type> p(value1,value2);
pair<type,type> p= make_pair(value1,value2);
***********************************/