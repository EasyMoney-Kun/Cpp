#include <iostream>
using namespace std;
#include<algorithm>
#include<functional>
#include<vector>
void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    sort(v.begin(), v.end(), greater<int>()); //大于最常用
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
template<class T> bool euqal_to<T> //=
template<class T> bool not_euqal_to<T> //!=
template<class T> bool grater<T> //>
template<class T> bool grater_equal<T> //>=
template<class T> bool less<T> //<
template<class T> bool less_equal<T> //<=
***********************************/